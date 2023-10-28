import Start from "../Start/start";
import { rl } from "../data/importdata";

export function End(keep_playing: boolean) {
  console.clear();
  if (keep_playing === true) {
    console.log("CONGRATULATION YOU WON");
  } else if (keep_playing === false) {
    console.log("GAME OVER");
  }
  if (rl.keyInYN(`Do you want another game ?\n`)) {
    Start();
  } else {
    console.log(`Okay , Good Bye !`);
  }
  return;
}
