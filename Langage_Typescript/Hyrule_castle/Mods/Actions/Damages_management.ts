import { Add_Damages_combat_log } from "../Display/display_damages";
import { Damages } from "../data/Damages";
import { Inventory, Item } from "../data/Iventory";
import { Units } from "../data/Unit";
import { Is_level_up } from "../game/End_of_fight";
import Init_damages from "../initialisation/initialisation_damages";
import { combat_log } from "../initialisation/initialisation_tower";
import { Damage_modif } from "./Damage_modifiers";


export function Damages_output(
  unit: Units,
  target: Units,
  damages: Damages,
  target_list: Units[]
) {
  const saveold_hp = unit.state.health.current;
  target.state.health.current -= Math.floor(damages.damages);
  Is_over_heal(target);
  if (damages.damages < 0) {
    damages.damages = saveold_hp - target.state.health.current;
  }
  Add_Damages_combat_log(target, unit, damages, combat_log);
  return damages;
}

export function Is_over_heal(unit: Units) {
  if (unit.state.health.current > unit.state.health.max) {
    unit.state.health.current = unit.state.health.max;
  }
  return unit;
}



export function heal(target: Units) {
  let heal: Damages = Init_damages();
  heal.damages = -100;
  return heal;
}

export function Restore(unit: Units ,target: Units) {
  if(target.state.mana != undefined) {
    const saveold_mp = target.state.mana.current
    target.state.mana.current += 100;
    Is_over_mana(target);
    const restored = saveold_mp - target.state.mana.current;
    combat_log.push(`${unit.name} Restore ${-restored} mana to ${target.name}`)
  }
  
}
function Is_over_mana(unit: Units) {
  if(unit.state.mana != undefined) {
    if (unit.state.mana.current > unit.state.mana.max) {
      unit.state.mana.current = unit.state.mana.max;
      return unit;
    }
  }
}

export function Fireball(unit: Units, target : Units) {
  let damages: Damages = Init_damages();
  damages.damages = 200;
  damages.damages = Damage_modif(unit,target,damages,"magic");
  damages.damages = Math.floor(damages.damages*1);
  return damages;
}

export function item_effect(item: Item, target : Units){
  let heal : number = 0;
  let mana : number = 0;
  let exp : number = 0;
  switch(item.name) {
    case "Low-level Potion":
      heal = Math.floor(target.state.health.max * 0.1);
      mana = 10;
      exp = 0;
    break;
    case "Potion":
      heal = Math.floor(target.state.health.max * 0.25);
      mana = 20;
      exp = 0;
    break;
    case "Good Potion":
      heal = Math.floor(target.state.health.max * 0.35);
      mana = 25;
      exp = 0;
    break;
    case "High-level Potion":
      heal = Math.floor(target.state.health.max * 0.5);
      mana = 50;
      exp = 0;
    break;
    case "Holy Potion":
      heal = Math.floor(target.state.health.max);
      if(target.state.mana)
      mana = target.state.mana.max;
      exp = 500;
    break;
  }
  target.state.health.current += heal;
  Is_over_heal(target);
  if(target.state.mana) {
    target.state.mana.current += mana ;
    Is_over_mana(target); 
  }
  if(target.state.level) {
    target.state.level.exp.current += exp;
    while(target.state.level.exp.current >= target.state.level.exp.max){
      Is_level_up(target);
    }
  }
  return;
}
