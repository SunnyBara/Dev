import { Damages_output, Fireball, Restore, heal, item_effect } from "./Damages_management";
import { Name_from_list, Search_in_list } from "../Search/search_functions";
import { Units } from "../data/Unit";
import { Display } from "../Display/display";
import { hero_list, inventory } from "../initialisation/initialisation_hero";
import { rl } from "../data/importdata";
import { Tower } from "../data/Tower";
import { Attack } from "./Damage_modifiers";
import { combat_log } from "../initialisation/initialisation_tower";
import { Item } from "../data/Iventory";

export function PlayerAction(unit: Units, fight_list: Units[], tower: Tower) {
  console.clear();
  Display(fight_list, tower.current_floor + 1);
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
  const fight_tab = ["Attack", "Skills"];
  if(inventory.items.length > 0) {
    fight_tab.push("Inventory");
  }
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
      chooseskill(unit, fight_list, tower);
      break;
    case 2:
      if(inventory.items.length > 0) {
        check_inventory(unit,fight_list,tower); 
      } 
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


export function chooseskill(unit: Units, fight_list: Units[], tower: Tower) {
  console.clear();
  Display(fight_list, tower.current_floor + 1);
  const Skills_names = ["Cheat Heal","Cheat Restore","Cheat Fireball"]
  const answers = rl.keyInSelect(Skills_names, `Choose your target`, {
    cancel: "Choose another attack",
  });
  switch (answers) {
    case -1:
      Letsfight(unit, fight_list, tower);
      return undefined;

    case 0:
      if(unit.state.mana != undefined && unit.state.mana.current >= 20) {
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
          heal(target_to_heal),
          hero_list
        )
        unit.state.mana.current -= 20;
      };
      } else {
        combat_log.push("Not enought mana");
        chooseskill(unit, fight_list, tower);
      }
        break;
        case 1:
          const target_to_restore: Units | undefined = Choosetarget(
            unit,
            fight_list,
            hero_list,
            tower
          );
          if (target_to_restore != undefined) {
            Restore(unit,target_to_restore);
          }
            break;
          case 2:
            if(unit.state.mana != undefined && unit.state.mana.current >= 20) {
              for (const fighter of fight_list) {
                Damages_output(
                  unit,fighter,
                  Fireball(unit, fighter),
                  fight_list
                )
              };
              unit.state.mana.current -= 20;
            } else {
              combat_log.push("Not enought mana");
              chooseskill(unit, fight_list, tower);
            }
            break;
 }
}

export function check_inventory(unit: Units, fight_list: Units[], tower: Tower) {
  console.clear();
  Display(fight_list, tower.current_floor + 1);
  const inventory_list : string[]= [];
  inventory.items.forEach((item) => {
   inventory_list.push(item.name);
  });
  const answers = rl.keyInSelect(inventory_list, `Choose your item`, {
    cancel: "Choose another attack",
  });
  switch (answers) {
    case -1:
      Letsfight(unit, fight_list, tower);
      return undefined;

    default :
      check_item(inventory_list[answers],unit, fight_list, tower);
    break;
 }
}

export function check_item(item_name : string ,unit: Units, fight_list: Units[], tower: Tower) {
  console.clear();
  Display(fight_list, tower.current_floor + 1);
  let choosen_item : Item | null = inventory.find_item(item_name)
  if(choosen_item){
    const answers = rl.keyInSelect(["Use"], `${choosen_item.name} : ${choosen_item.Description}\n ${choosen_item.count} left.`, {
      cancel: "Choose another attack",
    });
    switch (answers) {
      case -1:
        check_inventory(unit, fight_list, tower);
        return undefined;
  
      case 0 :
        const target = Choosetarget(unit, fight_list,hero_list, tower);
        if(target){
          let message = `${unit.name} used a ${choosen_item.name}`
          if(target.name === unit.name){
            message += ' on himself';
          } else {
            message += ` on ${target.name}`;
          }
          combat_log.push(message);
          item_effect(choosen_item,target) ;
          inventory.Use(choosen_item);
        }
      break;
   }
  }
}
