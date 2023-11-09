import { Add_Damages_combat_log } from "../Display/display_damages";
import { Damages } from "../data/Damages";
import { Units } from "../data/Unit";
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
