import { Add_Damages_combat_log } from "../Display/display_damages";
import { Damages } from "../data/Damages";
import { Units } from "../data/Unit";
import Init_damages from "../initialisation/initialisation_damages";
import { combat_log } from "../initialisation/initialisation_tower";
import { Is_it_dead } from "./Death_management";

export function Damages_output(
  unit: Units,
  target: Units,
  damages: Damages,
  target_list: Units[]
) {
  const saveold_hp = unit.state.health.current;
  target.state.health.current -= damages.damages;
  Is_over_heal(target);
  if (damages.damages < 0) {
    damages.damages = saveold_hp - target.state.health.current;
  }
  Add_Damages_combat_log(target, unit, damages, combat_log);
  Is_it_dead(target_list, target);

  return damages;
}

export function Is_over_heal(unit: Units) {
  if (unit.state.health.current > unit.state.health.max) {
    unit.state.health.current = unit.state.health.max;
  }
  return unit;
}

export function Attack(unit: Units): Damages {
  let damages: Damages = Init_damages();
  damages.damages = unit.characteristics.str;
  return damages;
}

// export function spell_damage(unit: Units, target: Units, spell_name: string) {
//     let damage: number  =
// }

export function heal(target: Units, target_list) {
  let heal: Damages = Init_damages();
  heal.damages = Math.floor(-target.state.health.max / 2);
  return heal;
}
