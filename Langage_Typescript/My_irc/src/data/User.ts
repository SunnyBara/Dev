import Room from "./Room";

export class User {
  private login: string;
  private password: string;
  private rooms: Room[];
  private friendList: User[];
  private user_Id: number;
  constructor(login: string, password: string) {
    this.login = login;
    this.password = password;
    this.rooms = [];
    this.friendList = [];
    this.user_Id = 0;
  }
  set _login(login: string) {
    this.login = login;
    return;
  }
  get _login() {
    return this.login;
  }
  set _password(password: string) {
    this.password = password;
    return;
  }
  get _user_Id() {
    return this.user_Id;
  }
  set _user_Id(user_Id: number) {
    this.user_Id = user_Id;
    return;
  }
  get _password() {
    return this.password;
  }
  add_Room(room: Room) {
    this.rooms.push(room);
    return;
  }

  add_Friend(user: User) {
    if (user.login !== this.login) {
      this.friendList.push(user);
    }
    return;
  }
}
