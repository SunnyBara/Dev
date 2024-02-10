//import { Message, User } from "./User";
export const mysql = require("mysql2");
import * as dotenv from "dotenv";
import { send } from "process";
dotenv.config();

// let user = new User();
// user.id = 8;
// let message = new Message();
// message.user_id = 8;
// message.message_content = "Models1";
// main();
// async function main() {
//   message.displayItem();
//   message.message_content = "pasModels1";
//   await message.get();
//   message.id = 0;
//   console.log(message);
//   message.message_content = "pasModels1";
//   await message.save();
// }

class Column {
  name: string;
  value?: any;
}

class Models {
  static query: string = "";
  protected static table: string = "modelss";
  protected listofcolumns: Column[];
  [key: string]: any;

  //InnerData
  private setattributes(attributes) {
    for (const column of this.listofcolumns) {
      this[`${column.name}`] = attributes[`${column.name}`];
    }
    return;
  }
  //Handle Name of table
  public static reset() {
    this.settable(this.name.toLowerCase() + "s");
  }
  public reset() {
    Models.settable(this.constructor.name.toLowerCase() + "s");
  }
  public static gettable() {
    if (this.table == "modelss") {
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

  // Models method
  static async all() {
    if (this.table == "modelss") {
      this.reset();
    }
    Models.query = `SELECT * FROM ${this.table}`;
    const result = await Models.execQuery();
    return this.buildanswer(result);
  }

  static async find(id: number) {
    if (this.table == "modelss") {
      this.reset();
    }
    Models.query = `SELECT * FROM ${this.table} WHERE id = ${id}`;
    const result = await Models.execQuery();
    return this.buildanswer(result);
  }

  static async where(item: Column) {
    if (this.table == "modelss") {
      this.reset();
    }
    Models.query = `Select * From ${this.table} Where ${item.name} = '${item.value}'`;
    const result = await Models.execQuery();
    let send;
    if (result[0].length > 1) {
      this.buildanswerlist(result);
    } else {
      this.buildanswer(result);
    }
    return send;
  }

  static buildanswerlist(result) {
    const listofsend: any[] = [];
    for (const data in result[0]) {
      const instance = new this();
      instance.setattributes(data);
      listofsend.push(instance);
    }
    return listofsend;
  }
  static buildanswer(result) {
    const instance = new this();
    instance.setattributes(result[0][0]);
    const send = instance;
    return send;
  }
  //Instance method
  public async save() {
    if (Models.table == "modelss") {
      this.reset();
    }
    if (this.id) {
      this.updateQuery();
    } else {
      this.insertQuery();
    }

    Models.execQuery();
    return this;
  }

  //Query aggregates
  public where(item: Column) {
    Models.query += ` WHERE ${item.name} = '${item.value}'`;
    return this;
  }

  //Query management
  public insertQuery() {
    const listcolumn: string[] = [];
    const lsitvalue: any[] = [];
    for (const key in this) {
      for (const column of this.listofcolumns) {
        if (key == column.name) {
          listcolumn.push(key);
          lsitvalue.push(this[key]);
        }
      }
    }
    Models.query =
      `INSERT INTO ${Models.table} (` +
      listcolumn.join(",") +
      ") VALUES ('" +
      lsitvalue.join("','") +
      "');";
    return;
  }
  public updateQuery() {
    const listcolumn: string[] = [];
    for (const key in this) {
      for (const column of this.listofcolumns) {
        if (key == column.name) {
          listcolumn.push(`${key} = '${this[key]}'`);
        }
      }
    }
    Models.query = `UPDATE ${Models.table} SET ` + listcolumn.join(",");
    this.where({ name: "id", value: `${this.id}` });
    return;
  }

  public static async execQuery() {
    console.log(this.query);
    const db = Models.connection();
    const result = await db.promise().query(this.query);
    db.end();
    Models.query = "";
    return result;
  }
}
class User extends Models {
  protected listofcolumns: Column[] = [
    { name: "id", value: 0 },
    { name: "user_login" },
    { name: "user_email" },
  ];
}

class Message extends Models {
  protected listofcolumns: Column[] = [
    { name: "id", value: 0 },
    { name: "user_id" },
    { name: "message_content" },
  ];
}

async function main() {
  const users = Models.all();
  const user1 = new User();
  user1.user_login = "michel";
  user1.user_email = "michel@gmail.com";
  user1.save();
  const user2 = await User.find(1);
  user2.user_email = "michel@gmail.com";
  user2.save();
}
main();
