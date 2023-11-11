import { Room } from './Room';
import { User } from './User';

export class Message {
  sender: User;

  receiver: User | Room;

  content: string;

  constructor(sender: User, receiver: User | Room, content: string) {
    this.sender = sender;
    this.receiver = receiver;
    this.content = content;
  }

  isReceiverUser(): this is { receiver: User } {
    return this.receiver instanceof User;
  }

  isReceiverRoom(): this is { receiver: Room } {
    return this.receiver instanceof Room;
  }
}

export function formatageMessage(message: Message) {
  message.content = message.content.replace(/'/gm, "''");
  return message;
}
