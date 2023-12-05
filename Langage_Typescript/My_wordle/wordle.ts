import askforarematche from "./end/end";
import game from "./game/game";
import initialisation from "./initialisation/initialisation";

export default function My_wordle() {
  game(initialisation());
  askforarematche();
  return;
}
