export default class Room {
  id_room?: number;

  name_room: string;

  id_admin_user?: number;

  Nb_User_Current?: number;

  max_user_in_room: number;

  constructor(name: string, max_user: number) {
    this.name_room = name;
    this.max_user_in_room = max_user;
  }
}
