import { Display } from "../Display/display";
import {
  Display_Combat_log,
  Reset_combat_log,
} from "../Display/display_damages";
import { Tower } from "../data/Tower";
import { Units } from "../data/Unit";
import { combat_log } from "../initialisation/initialisation_tower";

export default function Begin_of_turn(fight_list: Units[], tower: Tower) {
  Display(fight_list, tower.current_floor);
  Reset_combat_log(combat_log);
  return;
}
