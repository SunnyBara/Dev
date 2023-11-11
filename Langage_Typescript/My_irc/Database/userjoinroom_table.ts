import Room from "../src/data/Room";
import { User } from "../src/data/User";
import openDb from "./connection";
import { getInfoRoom } from "./room";
import { getUserInfo } from "./user_table";

export async function addUserJoinRoom(user: User, room: Room) {
  //add User & room id in User_to_room table;
  //how to use this function : addUserJoinRoom(user,room);
  const connection = openDb();
  user = await getUserInfo(user);
  room = await getInfoRoom(room);
  let query = `insert into User_To_Room (Id_User,Id_Room) VALUES ('${user._user_Id}','${room.id_room}');`;
  connection.query(query);
  connection.end();
  return;
}

export async function getUsersInRoom(room: Room): Promise<User[]> {
  //Return liste of the User in the room;
  //how to use this function const listOfUsers : User[] = getUsersInRoom(room);
  room = await getInfoRoom(room);
  const query = `SELECT * FROM User_To_Room WHERE Id_Room = ${room.id_room}`;
  const listOfUsers: User[] = [];
  const connection = openDb();
  const result = await connection.promise().query(query);
  for (const user_Ids of result[0]) {
    const theuser = await getUserInfo(user_Ids.Id_User);
    listOfUsers.push(theuser);
  }
  connection.end();
  return listOfUsers;
}

export async function getRoomsOfUser(user: User): Promise<Room[]> {
  //Return liste of the Rooms where the User is;
  //how to use this function : const listOfRoom: Room[] = getRoomOfUser(user);
  user = await getUserInfo(user);
  const query = `SELECT * FROM User_To_Room WHERE Id_User = ${user._user_Id}`;
  const listOfRoom: Room[] = [];
  const connection = openDb();
  const result = await connection.promise().query(query);
  for (const room_Ids of result[0]) {
    const room = await getInfoRoom(room_Ids.Id_Room);
    listOfRoom.push(room);
  }
  connection.end();
  return listOfRoom;
}
export async function isUserInThisRoom(
  user: User,
  room: Room
): Promise<boolean> {
  //Verify if the user  is in the Room  in User_To_Room table
  //how to use this function const myBoolean : Boolean = isUserInThisRoom(user,room) or if(isUserInThisRoom(user,room)){};
  user = await getUserInfo(user);
  room = await getInfoRoom(room);
  const connection = openDb();
  let query = `SELECT * FROM User_To_Room WHERE Id_User = ${user._user_Id} AND Id_Room = ${room.id_room} ;`;
  const result = await connection.promise().query(query);
  connection.end();
  if (result[0].length > 0) {
    return true;
  }
  return false;
}

export async function deleteAllRoomOfTheUser(user: User) {
  // Removes all room of the user from the User_To_Room table;
  // how to use this function : deleteAllRoomOfTheUser(user);
  const connection = openDb();
  user = await getUserInfo(user);
  let query = `DELETE FROM User_To_Room WHERE Id_User = '${user._user_Id}';`;
  connection.promise().query(query);
  connection.end();
  return;
}

export async function deleteAllUsersInTheRoom(room: Room): Promise<Room> {
  // Removes all user in the room from the User_To_Room table (it will delete the admin as well);
  // how to use this function : room = deleteAllUserInTheRoom(room);
  room = await getInfoRoom(room);
  const connection = openDb();
  let query = `DELETE FROM User_To_Room WHERE Id_Room = '${room.id_room}';`;
  connection.promise().query(query);
  query = `UPDATE Room SET Nb_User_current = 0 WHERE Room_name = '${room.name_room}' `;
  await connection.promise().query(query);
  connection.end();
  return await getInfoRoom(room);
}
