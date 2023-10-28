import { End } from "./End/End";
import Game from "./game/game";
import Initialisation from "./initialisation/initialisation";

export function Hyrule_castle() {
    End(Game(Initialisation()));
}

