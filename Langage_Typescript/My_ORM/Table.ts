export const mysql = require("mysql2");
import * as dotenv from "dotenv";
dotenv.config();
class Column {
  name: string;
  value: any;
}

export class Models {
  protected listofcolumns: Column[];
  protected static table: string = "reset";
  [key: string]: any;

  //Handle Name of table
  public static reset() {
    this.settable(this.name.toLowerCase() + "s");
  }
  public static gettable() {
    if (this.table == "reset") {
      this.reset();
    }
    return this.table;
  }
  public static settable(newname: string) {
    this.table = newname;
    return;
  }
  //Databse configuration
  private static connection() {
    return mysql.createConnection({
      host: process.env.DB_HOST,
      user: process.env.DB_USERNAME,
      password: process.env.DB_PASSWORD,
      database: process.env.DB_DATABASE,
    });
  }

  private async validateId() {
    if (this.id != undefined) {
      const db = Models.connection();
      const result = await db
        .promise()
        .query(
          `SELECT * FROM ${this.constructor.name.toLowerCase()}s WHERE id = ${
            this.id
          };`
        );
      db.end();
      if (result[0].length > 0) {
        return true;
      } else {
        return false;
      }
    }
    return true;
  }

  public async del() {
    if (this.id == 0) {
      await this.get();
    }
    if ((await this.validateId()) && this.id != undefined) {
      let db = Models.connection();
      db.promise().query(
        `DELETE FROM ${this.constructor.name.toLowerCase()}s WHERE id = ${
          this.id
        }`
      );
      db.end();
    }
    return;
  }

  private async buildValideList(): Promise<Column[]> {
    let columns = this.getcolumns();
    let attributes = this.getattributes();
    let validlist: Column[] = [];
    for (const column of columns) {
      if (this.testcolumn(column, attributes[columns.indexOf(column)]) == 1) {
        validlist.push({
          name: column,
          value: attributes[columns.indexOf(column)],
        });
      }
    }
    return validlist;
  }

  private static async Where(tabvalide: Column[]) {
    let query = `WHERE ${tabvalide[0].name} = '${tabvalide[0].value}'`;
    return query;
  }

  private async queryAnd(tabvalide: Column[]) {
    let query: string = "";
    let incr = 1;
    while (incr < tabvalide.length) {
      query += ` AND ${tabvalide[incr].name} = '${tabvalide[incr].value}'`;
      incr += 1;
    }
    return query;
  }

  public async buildgetQuery() {
    let query = `Select * From ${this.constructor.name.toLowerCase()}s `;
    const tabvalide: Column[] = await this.buildValideList();
    switch (tabvalide.length) {
      case 0:
        console.log("No enought informations to build a conditonal query");
        query = "KO";
        break;
      case 1:
        query += await Models.Where(tabvalide);
        break;
      default:
        query += await Models.Where(tabvalide);
        query += await this.queryAnd(tabvalide);
        break;
    }
    return query;
  }

  private async retrieveDefaultIdValue() {
    for (const column of this.listofcolumns) {
      if (column.name == "id") {
        return column.value;
      }
    }
  }

  public async get() {
    const default_id = await this.retrieveDefaultIdValue();
    if ((await this.validateId()) || this.id == default_id) {
      let query = await this.buildgetQuery();
      if (query == "KO") {
        return;
      }
      query += " LIMIT 1;";
      const result = await this.request(query);
      if (result != undefined) {
        this.setattributes(result);
      } else {
        console.log("No match found");
      }
    } else {
      console.log(`id not found`);
    }
    return;
  }

  public static async all(condition?: string) {
    let query = `SELECT * FROM ${this.name.toLowerCase()}s `;
    if (condition != undefined) {
      query += condition;
    }
    query += ";";
    const db = this.connection();
    const result = await db.promise().query(query);
    db.end();
    return result[0];
  }

  private testcolumn(column: string, attribute: any): number {
    let cr = -1;
    this.listofcolumns.every((validecolum) => {
      if (column == validecolum.name) {
        cr = 1;
        if (attribute == validecolum.value || attribute == undefined) {
          cr = 0;
        }
        return false;
      } else {
        return true;
      }
    });

    if (cr == -1) console.log(`${column} n'est pas une colonne valide`);
    return cr;
  }

  private async buildInsertQuery(): Promise<string> {
    let query = `INSERT INTO ${this.constructor.name.toLowerCase()}s `;
    const tabvalide: Column[] = await this.buildValideList();
    switch (tabvalide.length) {
      case 0:
        console.log("No enought informations to build a conditonal query");
        query = "KO";
        break;
      default:
        query += await this.queryInsert(tabvalide);
        break;
    }
    return query;
  }

  private async queryInsert(tabvalide: Column[]) {
    let query: string = "(";
    let endofquery: string = "(";
    let incr = 0;
    while (incr < tabvalide.length - 1) {
      query += `${tabvalide[incr].name}, `;
      endofquery += `'${tabvalide[incr].value}',`;
      incr += 1;
    }
    query += `${tabvalide[incr].name}) `;
    endofquery += `'${tabvalide[incr].value}');`;
    query += "VALUES" + endofquery;
    return query;
  }

  private async queryUpdate(tabvalide: Column[]) {
    let query: string = `${tabvalide[0].name} = '${tabvalide[0].value}' `;
    let incr = 1;
    while (incr < tabvalide.length) {
      query += `,${tabvalide[incr].name} = '${tabvalide[incr].value}' `;
      incr += 1;
    }
    return query;
  }

  private async buildUpdateQuery(): Promise<string> {
    let query = `UPDATE ${this.constructor.name.toLowerCase()}s SET `;
    const tabvalide: Column[] = await this.buildValideList();
    switch (tabvalide.length) {
      case 0:
        console.log("No enought informations to build a conditonal query");
        query = "KO";
        break;
      default:
        query += await this.queryUpdate(tabvalide);
        query += await Models.Where([{ name: "id", value: this.id }]);
        break;
    }
    return query;
  }

  public async save() {
    let query = "";
    if (await this.validateId()) {
      query = await this.buildUpdateQuery();
    } else {
      query = await this.buildInsertQuery();
    }

    if (query != "KO") {
      const db = Models.connection();
      const result = await db.promise().query(query);
      db.end();
    }
    return;
  }

  private getattributes() {
    const attributes: any[] = [];

    for (const key in this) {
      if (!(typeof this[key] == "function") && key != "listofcolumns") {
        attributes.push(this[key]);
      }
    }
    return attributes;
  }

  private setattributes(attributes) {
    for (const column of this.listofcolumns) {
      this[`${column.name}`] = attributes[`${column.name}`];
    }
    return;
  }

  private getcolumns(): string[] {
    const columns: string[] = [];
    for (const key in this) {
      if (!(typeof this[key] == "function") && key != "listofcolumns") {
        columns.push(key);
      }
    }
    return columns;
  }

  public displayItem() {
    const columns = this.getcolumns();
    const attributes = this.getattributes();
    const display: string[] = [];
    let i = 0;
    while (i < columns.length) {
      display[i] = `${columns[i]} : ${attributes[i]}`;
      i += 1;
    }
    console.log(display);
  }

  public belongsto(classname: string, link?: string) {
    let query;
    let linker = classname + ".id";
    if (link != undefined) {
      linker = link;
    }
    query = `SELECT * FROM ${this.name}s INNER JOIN ${classname}s on ${linker} = message.${linker}`;
    query += Models.Where([{ name: "id", value: this.id }]);
    const db = Models.connection();
    const result = db.promise.query(query);
    return result[0];
  }

  private async request(query: string) {
    const db = Models.connection();
    const result = await db.promise().query(query);
    db.end();
    return result[0][0];
  }
}
