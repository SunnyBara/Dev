import { rl } from "../lib/lib";
import my_wordle from "../wordle";

export default function askforarematche() {
  if (rl.keyInYN(`Do you want another game ?\n`)) {
    my_wordle();
  } else {
    console.log(`Okay , Good Bye !`);
  }
}
