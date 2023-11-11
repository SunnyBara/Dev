import { Message } from '../src/data/Message';
import { Room } from '../src/data/Room';
import { User } from '../src/data/User';
import { openDb } from './connection';
import { RegexDate } from './date';
import { getInfoRoom } from './room';
import { getUserInfo } from './user_table';

export async function addRoomMessage(message: Message) {
  // Add a content message with the date from User in the Room_Message table;
  // how to use this function : if(message.isReceiverRoom()) {addRoomMessage(message : Message);}
  message.receiver = message.receiver as Room;
  const query = `INSERT INTO Room_Message (Id_Room,Id_User,Content) VALUES (${message.receiver.id_room}, ${message.sender._user_Id}, '${message.content}');`;
  const connection = openDb();
  connection.promise().query(query);
  connection.end();
}

export async function getMessageOfTheRoom(
  room: Room,
  from?: string,
  to?: string,
): Promise<Message[]> {
  // This function Return a Liste of Message in this Room from Message_Room table
  // how to use this function :
  //  listofmessage = await getMessageOfTheRoom(room,from or undefined,to or undefined);
  // For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  const listOfMessage: Message[] = [];
  if (from && !RegexDate(from)) {
    return [];
  } if (to && !RegexDate(to)) {
    return [];
  }
  return new Promise(async (resolve, reject) => {
    room = await getInfoRoom(room);
    const connection = openDb();
    try {
      let query: string = `SELECT * FROM Room_Message where Id_Room = ${room.id_room} `;
      if (from && to) {
        query += `AND Date_Send BETWEEN '${from}' AND '${to}';`;
      } else if (from) {
        query += `AND Date_Send > '${from}';`;
      } else if (to) {
        query += `AND Date_Send < '${to}';`;
      }
      const result = await connection.promise().query(query);
      connection.end();
      for (const results of result[0]) {
        const sender = await getUserInfo(results.Id_User);
        const newmessage = new Message(sender, room, results.Content);
        listOfMessage.push(newmessage);
      }
      resolve(listOfMessage);
    } catch (error) {
      connection.end();
      reject(error);
    }
  });
}

export async function getMessageOfTheUser(
  user: User,
  from?: string,
  to?: string,
): Promise<Message[]> {
  // This function Return a Liste of Message of the User in  Rooms from Message_Room table
  // how to use this function :
  //  listofmessage = await getMessageOfTheUser(user,from or undefined,to or undefined);
  // For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  const listOfMessage: Message[] = [];

  return new Promise(async (resolve, reject) => {
    user = await getUserInfo(user);
    const connection = openDb();
    try {
      let query: string = `SELECT * FROM Room_Message where Id_User = ${user._user_Id} `;
      if (from && to) {
        query += `AND Date_Send BETWEEN '${from}' AND '${to}';`;
      } else if (from) {
        query += `AND Date_Send > '${from}';`;
      } else if (to) {
        query += `AND Date_Send < '${to}';`;
      }
      const result = await connection.promise().query(query);
      connection.end();
      for (const results of result[0]) {
        const receiver = await getInfoRoom(results.Id_Room);
        const newmessage = new Message(user, receiver, results.Content);
        listOfMessage.push(newmessage);
      }
      resolve(listOfMessage);
    } catch (error) {
      connection.end();
      reject(error);
    }
  });
}

export async function deleteMessageOfUser(
  user: User,
  from?: string,
  to?: string,
) {
  // This function delete the Messages of the User sender in  Rooms from Message_Room table
  // how to use this function : await deleteMessageOfUser(user,from or undefined,to or undefined);
  // For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  if (from !== undefined && !RegexDate(from)) {
    return [];
  } if (to !== undefined && !RegexDate(to)) {
    return [];
  }
  user = await getUserInfo(user);
  const connection = openDb();
  try {
    let query: string = `DELETE FROM Room_Message WHERE Id_User = ${user._user_Id} `;
    if (from && to) {
      query += `AND Date_Send BETWEEN '${from}' AND '${to}';`;
    } else if (from) {
      query += `AND Date_Send > '${from}';`;
    } else if (to) {
      query += `AND Date_Send < '${to}';`;
    }
    await connection.promise().query(query);
    connection.end();
  } catch (error) {
    connection.end();
  }
}

export async function deleteMessageOfRoom(
  room: Room,
  from?: string,
  to?: string,
) {
  // This function delete the Messages of the User sender in  Rooms from Message_Room table
  // how to use this function : await deleteMessageOfUser(user,from or undefined,to or undefined);
  // For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  if (from && !RegexDate(from)) {
    return [];
  } if (to && !RegexDate(to)) {
    return [];
  }
  room = await getInfoRoom(room);
  const connection = openDb();
  try {
    let query: string = `DELETE FROM Room_Message WHERE Id_Room = ${room.id_room} `;
    if (from && to) {
      query += `AND Date_Send BETWEEN '${from}' AND '${to}';`;
    } else if (from) {
      query += `AND Date_Send > '${from}';`;
    } else if (to) {
      query += `AND Date_Send < '${to}';`;
    }
    await connection.promise().query(query);
    connection.end();
  } catch (error) {
    connection.end();
  }
}
