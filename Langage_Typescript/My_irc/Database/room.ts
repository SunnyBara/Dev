import Room from "../src/data/Room";
import { User } from "../src/data/User";
import openDb from "./connection";
import { getUserInfo } from "./user_table";
import { addUserJoinRoom, deleteAllUsersInTheRoom } from "./userjoinroom_table";

export async function modifNumberUserInRoom(
  join: boolean,
  room: Room
): Promise<Room> {
  //Add or Subract 1 on NumberofCurrentUser of the room
  //how to use this function : room = modifNumberUserInRoom(true/false , room);
  return new Promise(async (resolve, reject) => {
    let query = `SELECT Nb_User_current FROM Room WHERE Room_name = '${room.name_room}'`;
    try {
      const connection = openDb();
      var result = await connection.promise().query(query);
      let nb_user: number = result[0][0].Nb_User_current;
      if (join) {
        nb_user += 1;
      } else {
        nb_user -= 1;
      }
      query = `UPDATE Room SET Nb_User_current = ${nb_user} WHERE  Room_name = '${room.name_room}' `;
      var result = await connection.promise().query(query);
      connection.end();
      room = await getInfoRoom(room);
      resolve(room);
    } catch (error) {
      reject(error);
    }
  });
}

export async function getInfoRoom(info: any): Promise<Room> {
  //return all the info  of the room from Room table
  //how to use this function : room = getInfoRoom(room) or room = getInforRoom(id) or room = getInfoRoom(room.name_room);
  return new Promise(async (resolve, reject) => {
    let query = `SELECT * FROM Room WHERE `;
    if (typeof info === "number") {
      query += `Id = ${info};`;
    } else if (typeof info === "string") {
      query += `Room_Name = '${info}';`;
    } else {
      query += `Room_Name = '${info.name_room}';`;
    }
    const connection = openDb();
    try {
      const result = await connection.promise().query(query);
      const room = new Room(result[0][0].Room_Name, result[0][0].Nb_User_Max);
      room.Nb_User_Current = result[0][0].Nb_User_Current;
      room.id_admin_user = result[0][0].Id_User_Admin;
      room.id_room = result[0][0].Id;
      connection.end();
      resolve(room);
    } catch (error) {
      connection.end();
      reject(error);
    }
  });
}

export async function createRoom(room: Room, user: User): Promise<Room> {
  //return a new room and add the Admin user in the User_to_Room table;
  //how to use this function :  room =  createRoom(room);
  const connection = openDb();
  user = await getUserInfo(user);
  let query = `INSERT INTO Room (Room_Name,Nb_User_Max,Id_User_Admin) VALUES ('${room.name_room}','${room.max_user_in_room}','${user._user_Id}');`;
  await connection.promise().query(query);
  await modifNumberUserInRoom(true, room);
  await addUserJoinRoom(user, room);
  room = await getInfoRoom(room);
  connection.end();
  return room;
}

export async function deleteRoom(room: Room) {
  //remove room in table Room
  //how to use this function : deleteRoom(room);
  await deleteAllUsersInTheRoom(room);
  const connection = openDb();
  let query = `DELETE FROM Room WHERE Room_Name = '${room.name_room}';`;
  connection.promise().query(query);
  connection.end();
  return;
}

export async function isRoomExist(room: Room): Promise<boolean> {
  //Verify if the Room is in the Room table
  //how to use this function const myBoolean : Boolean = isRoomExist(room) or if(isRoomExist(room)){};
  const connection = openDb();
  let query = `SELECT * FROM Room WHERE Room_Name = '${room.name_room}';`;
  const result = await connection.promise().query(query);
  connection.end();
  if (result[0].length > 0) {
    return true;
  }
  return false;
}

export async function listOfExistingRoom(): Promise<Room[]> {
  // Return a List of existing rooms;
  // how to use this function  :  const listofroom : Room[] = listOfExistingRoom();

  return new Promise(async (resolve, reject) => {
    const listOfRoom: Room[] = [];
    const connection = openDb();
    const query = 'Select * From Room;';

    try {
      const results = await connection.promise().query(query);
      for (const result of results[0]) {
        let newroom = new Room(result.Room_Name, result.Nb_User_Max);
        newroom = await getInfoRoom(newroom);
        listOfRoom.push(newroom);
      }
      connection.end();
      resolve(listOfRoom);
    } catch (error) {
      connection.end();
      reject(error);
    }
  });
}
