import { Message } from '../src/data/Message';
import { addPrivateMessage } from './private_message';
import { getInfoRoom } from './room';
import { addRoomMessage } from './room_messages';
import { getUserInfo } from './user_table';

export async function addMessage(message: Message) {
  // Add message in either Private_message and Room_message
  // How to use this function : await addMessage(message);
  message = await formatageMessage(message);
  message.sender = await getUserInfo(message.sender);
  if (message.isReceiverUser()) {
    message.receiver = await getUserInfo(message.receiver);
    await addPrivateMessage(message);
  } else if (message.isReceiverRoom()) {
    message.receiver = await getInfoRoom(message.receiver);
    await addRoomMessage(message);
  }
  return;
}

export async function formatageMessage(message: Message): Promise<Message> {
  // Replace ' by '' in string that allow to send the content in the DataBase;
  // How to use this function : message = await formatageMessage(message);
  message.content = message.content.replace(/'/gm, "''");
  return message;
}
