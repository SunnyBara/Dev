import { User } from '../src/data/User';
import openDb from './connection';
import { deleteAllRoomOfTheUser } from './userjoinroom_table';

export async function addUser(user: User) {
  // add new User in table User
  // how to use this function : addUser(user);
  const connection = openDb();
  const query = `INSERT INTO User (User_name,User_password) VALUES ('${user._login}','${user._password}');`;
  console.log(query);
  connection.query(query);
  connection.end();
}

export async function removeUser(user: User) {
  // remove  User in table User
  // how to use this function : removeUser(user);
  user = await getUserInfo(user);
  deleteAllRoomOfTheUser(user);
  const connection = openDb();
  const query = `DELETE FROM User WHERE User_name = '${user._login}';`;
  connection.query(query);
  connection.end();
}

export async function isUserExist(user: User) {
  // Verify if the user is in the User table
  // how to use this function : const myboolean : Boolean = isUserExist(user) or if(isUserExist){};
  const connection = openDb();
  const query = `SELECT * FROM User WHERE User_name = '${user._login}';`;
  const result = await connection.promise().query(query);
  connection.end();
  if (result[0].length > 0) {
    return true;
  }
  return false;
}

export async function getUserInfo(info: any): Promise<User> {
  // return user info  from User table
  // how to use this function :
  // user = getUserinfo(user) or user = getUserinfo(id) or user = getUserinfo(user.login);
  return new Promise(async (resolve, reject) => {
    let query = 'SELECT * FROM User WHERE ';
    if (typeof info === 'number') {
      query += `Id = ${info};`;
    } else if (typeof info === 'string') {
      query += `User_name = '${info}';`;
    } else {
      query += `User_name = '${info.login}';`;
    }
    const connection = openDb();
    try {
      const result = await connection.promise().query(query);
      const theuser = new User(
        result[0][0].User_Name,
        result[0][0].User_Password,
      );
      theuser._user_Id = result[0][0].Id;
      connection.end();
      resolve(theuser);
    } catch (error) {
      connection.end();
      reject(error);
    }
  });
}
