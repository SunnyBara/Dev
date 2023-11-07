import { Damages_output, heal } from "./Damages_management";
import { Name_from_list, Search_in_list } from "../Search/search_functions";
import { Units } from "../data/Unit";
import { Display } from "../Display/display";
import { hero_list } from "../initialisation/initialisation_hero";
import { rl } from "../data/importdata";
import { Tower } from "../data/Tower";
import { Attack } from "./damage_modifiers";

export function PlayerAction(unit: Units, fight_list: Units[], tower: Tower) {
  const tab: string[] = ["Fight", "Run away"];
  const answers = rl.keyInSelect(tab, `It's ${unit.name} 's turns`, {
    cancel: "Leave tower",
  });
  switch (answers) {
    case 0:
      Letsfight(unit, fight_list, tower);
      break;
    case 1:
      console.log("fonction de fuite");
      break;
    case -1:
      return false;
  }
  return true;
}

function Letsfight(unit: Units, fight_list: Units[], tower: Tower) {
  const fight_tab = ["Attack", "Heal"];
  console.clear();
  Display(fight_list, tower.current_floor + 1);
  const answers = rl.keyInSelect(fight_tab, `Choose your action`, {
    cancel: "Back to previous options",
  });
  switch (answers) {
    case 0:
      const target_to_attack: Units | undefined = Choosetarget(
        unit,
        fight_list,
        fight_list,
        tower
      );
      if (target_to_attack !== undefined) {
        Damages_output(unit, target_to_attack, Attack(unit,target_to_attack), fight_list);
      }

      break;
    case 1:
      const target_to_heal: Units | undefined = Choosetarget(
        unit,
        fight_list,
        hero_list,
        tower
      );
      if (target_to_heal != undefined) {
        Damages_output(
          unit,
          target_to_heal,
          heal(target_to_heal, hero_list),
          hero_list
        );
      }
      break;
    case -1:
      PlayerAction(unit, fight_list, tower);
      break;
  }
}
function Choosetarget(
  unit: Units,
  fight_list: Units[],
  target_list: Units[],
  tower: Tower
): Units | undefined {
  console.clear();
  Display(fight_list, tower.current_floor + 1);
  const target_name_list = Name_from_list(target_list);
  const answers = rl.keyInSelect(target_name_list, `Choose your target`, {
    cancel: "Choose another attack",
  });
  switch (answers) {
    case -1:
      Letsfight(unit, fight_list, tower);
      return undefined;

    default:
      if (answers !== undefined) {
        return Search_in_list(target_name_list[answers], target_list);
      }
  }
  return undefined;
}
