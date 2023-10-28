import { display_big_zelda, display_gameover } from "../Ascii_Art";
import { Hyrule_castle } from "../Hyrule_castle";
import { rl } from "../data/importdata";
import Initialisation from "../initialisation/initialisation";

export function End(keep_playing: boolean) {
  console.clear();
  display_big_zelda();
  if (keep_playing === true) {
    console.log("CONGRATULATION YOU WON");
  } else if (keep_playing === false) {
    display_gameover();
  }
  if (rl.keyInYN(`Do you want another game ?\n`)) {
    Hyrule_castle();
  } else {
    console.log(`Okay , Good Bye !`);
  }
  return;
}
