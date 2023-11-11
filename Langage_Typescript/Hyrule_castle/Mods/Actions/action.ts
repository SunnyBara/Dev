import { Units } from "../data/Unit";
import { hero_list } from "../initialisation/initialisation_hero";
import { Mobaction } from "./Mob_action";
import { PlayerAction } from "./player_action";
import { Checkteamalive } from "./Check_fighters";
import { Tower } from "../data/Tower";
import { Damages } from "../data/Damages";
import { combat_log } from "../initialisation/initialisation_tower";
import { Display_Combat_log, Reset_combat_log } from "../Display/display_damages";
import { End_of_fight } from "../game/End_of_fight";
import { Kill_unit } from "./Death_management";
import { Display } from "../Display/display";

export function Action(
  initiative: Units[],
  fight_list: Units[],
  tower: Tower
): boolean {
  for (const unit of initiative) {
    if (unit.type === "trash_mobs" || unit.type === "boss") {
      const recap: Damages | void = Mobaction(unit, hero_list);
      Kill_unit(hero_list);
      if (Checkteamalive(hero_list)) {
        return false;
      }
    } else if (unit.type == "hero") {
      if (!PlayerAction(unit, fight_list, tower)) {
        return false;
      }
      Kill_unit(fight_list);
      if (Checkteamalive(fight_list)) {
        Reset_combat_log(combat_log);
        combat_log.push("Ennemies has been defeated");
        End_of_fight();
        return true;
      }
    }
  }
  return true;
}
