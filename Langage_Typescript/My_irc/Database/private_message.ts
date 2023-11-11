import { Message } from "../src/data/Message";
import { User } from "../src/data/User";
import { openDb } from "./connection";
import { RegexDate } from "./date";
import { getUserInfo } from "./user_table";

export async function addPrivateMessage(message: Message) {
  //Add a content message with the date from User in the Private_message table;
  //how to use this function : if(message.isReceiverRoom()) {addRoomMessage(message : Message);}
  message.receiver = message.receiver as User;
  let query = `INSERT INTO Private_Message (Id_Receiver,Id_Sender,Content) VALUES (${message.receiver._user_Id}, ${message.sender._user_Id}, '${message.content}');`;
  const connection = openDb();
  connection.promise().query(query);
  connection.end();
  return;
}

export async function getMessageSendPrivate(
  user: User,
  from?: string,
  to?: string
): Promise<Message[]> {
  //This function Return a Liste of Message of the User in  private from Private_message table
  //how to use this function : listofmessage = await getMessageOfTheUserPrivate(user,from or undefined,to or undefined);
  //For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  const listOfMessage: Message[] = [];

  return new Promise(async (resolve, reject) => {
    user = await getUserInfo(user);
    const connection = openDb();
    try {
      let query: string = `SELECT * FROM Private_Message WHERE Id_Sender = ${user._user_Id} `;
      if (from && to) {
        query += `AND Date_Send BETWEEN '${from}' AND '${to}';`;
      } else if (from) {
        query += `AND Date_Send > '${from}';`;
      } else if (to) {
        query += `AND Date_Send < '${to}';`;
      }
      console.log(query);
      const result = await connection.promise().query(query);
      connection.end();
      for (const results of result[0]) {
        console.log(results);
        const receiver = await getUserInfo(results.Id_Receiver);
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

export async function getMessageReceivePrivate(
  user: User,
  from?: string,
  to?: string
): Promise<Message[]> {
  //This function Return a Liste of Message of the User in  private from Private_message table
  //how to use this function : listofmessage = await getMessageOfTheUserPrivate(user,from or undefined,to or undefined);
  //For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  const listOfMessage: Message[] = [];

  return new Promise(async (resolve, reject) => {
    user = await getUserInfo(user);
    const connection = openDb();
    try {
      let query: string = `SELECT * FROM Private_Message WHERE Id_Receiver = ${user._user_Id} `;
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
        const receiver = await getUserInfo(results.Id_Receiver);
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

export async function deleteMessageOfUserPrivate(
  user: User,
  from?: string,
  to?: string
) {
  //This function delete the Messages of the User sender in  Rooms from Message_Room table
  //how to use this function : await deleteMessageOfUser(user,from or undefined,to or undefined);
  //For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  if (from !== undefined && !RegexDate(from)) {
    return [];
  } else if (to !== undefined && !RegexDate(to)) {
    return [];
  }
  user = await getUserInfo(user);
  const connection = openDb();
  try {
    let query: string = `DELETE FROM Private_Message WHERE Id_Sender = ${user._user_Id} `;
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
  return;
}

export async function deleteMessageReceived(
  receiver: User,
  from?: string,
  to?: string
) {
  //This function delete the Messages of the User received from Private_message table
  //how to use this function : await deleteMessageOfUser(user,from or undefined,to or undefined);
  //For date => use the format 'YYYY-MM-JJ HH:MM:SS'
  if (from !== undefined && !RegexDate(from)) {
    return [];
  } else if (to !== undefined && !RegexDate(to)) {
    return [];
  }
  receiver = await getUserInfo(receiver);
  const connection = openDb();
  try {
    let query: string = `DELETE FROM Private_Message WHERE Id_Receiver = ${receiver._user_Id} `;
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
  return;
}
