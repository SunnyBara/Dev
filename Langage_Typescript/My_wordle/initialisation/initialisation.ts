import { getRandomWord } from "../lib/lib";
import displayRules from "./displayRules";

export default function initialisation(): string {
  console.log(`Hello, let's play a game!`);
  displayRules();
  return getRandomWord();
}
