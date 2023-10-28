import { Display_gameover } from "../Display/Ascii_Art";
import { Hyrule_castle } from "../Hyrule_castle";
import { rl } from "../data/importdata";

export function End(keep_playing: boolean) {
  console.clear();
  Display_gameover();
  if (keep_playing === true) {
    console.log("CONGRATULATION YOU WON");
  } else if (keep_playing === false) {
    Display_gameover();
  }
  if (rl.keyInYN(`Do you want another game ?\n`)) {
    Hyrule_castle();
  } else {
    console.log(`Okay , Good Bye !`);
  }
  return;
}
