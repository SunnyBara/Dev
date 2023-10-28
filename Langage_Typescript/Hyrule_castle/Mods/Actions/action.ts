import { Units } from "../data/Unit";
import { hero_list } from "../initialisation/initialisation_hero";
import { Mobaction } from "./Mob_action";
import { PlayerAction } from "./player_action";
import { Checkteamalive } from "./Check_fighters";
import { Tower } from "../data/Tower";
import { Damages } from "../data/Damages";
import { combat_log } from "../initialisation/initialisation_tower";

export function Action(
  initiative: Units[],
  fight_list: Units[],
  tower: Tower
): boolean {
  for (const unit of initiative) {
    if (unit.type === "trash_mobs" || unit.type === "boss") {
      const recap: Damages | void = Mobaction(unit, hero_list);
      if (Checkteamalive(hero_list)) {
        return false;
      }
    } else if (unit.type == "hero") {
      if (!PlayerAction(unit, fight_list, tower)) {
        return false;
      }
      if (Checkteamalive(fight_list)) {
        combat_log.push("Ennemies has been defeated");
      }
    }
  }
  return true;
}
