import displayword from "./diplayword";
import gameplay from "./gameplay";
import { makeaguess } from "./makeaguess";

export default function game(wordtoguess: string): boolean {
  let tryremaining: number = 6;
  let wordtodisplay: string;
  let stillingame: boolean = true;
  while (stillingame === true && tryremaining > 0) {
    console.log(`${tryremaining} try remaining`);
    wordtodisplay = gameplay(makeaguess(), wordtoguess);
    stillingame = displayword(wordtodisplay, wordtoguess);
    tryremaining -= 1;
  }
  if (tryremaining === 0) {
    console.log(`You missed the word...`);
    return false;
  }
  return true;
}
