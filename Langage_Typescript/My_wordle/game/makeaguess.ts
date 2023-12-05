import displayRules from "../initialisation/displayRules";
import { getInput } from "../lib/lib";

function testsize(playerinput: string): boolean {
  let cr: boolean = false;
  if (playerinput.length === 5) {
    cr = true;
  }
  return cr;
}

function testonlyupperchar(playerinput: string): boolean {
  let cr: boolean = true;
  if (playerinput.match(/[^A-Z]/)) {
    cr = false;
  }
  return cr;
}

export function makeaguess(): string {
  let playerinput: string = "";
  console.log(`\nLet's make a guess`);
  playerinput = getInput(playerinput);
  if (playerinput.toLocaleUpperCase() === "-RULES") {
    displayRules();
  } else if (playerinput.toLocaleUpperCase() === "-HELP") {
  } else if (playerinput.toLocaleUpperCase() === "-WORDS") {
  } else if (playerinput.toLocaleUpperCase() === "-EXIT") {
  } else {
    if (!testsize(playerinput) || !testonlyupperchar(playerinput)) {
      console.log(
        `Input rejected !\nTake a cares of the rules !\n(type '-rules' to see them again.) `
      );
    } else {
      return playerinput;
    }
  }
  playerinput = makeaguess();
  return playerinput;
}
