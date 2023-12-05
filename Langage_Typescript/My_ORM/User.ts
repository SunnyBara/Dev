import { Models } from "./Table";

export class User extends Models {
  protected listofcolumns: any[] = [
    { name: "id", value: 0 },
    { name: "user_login" },
    { name: "user_email" },
  ];
  public id: number;
  public user_email: string;
  public user_login: string;
}

export class Message extends Models {
  protected listofcolumns: any[] = [
    { name: "id", value: 0 },
    { name: "user_id" },
    { name: "message_content" },
  ];
  public id: number;
  public user_id: number;
  public message_content: string;

  public user() {
    return this.belongsTo(User);
  }
}
