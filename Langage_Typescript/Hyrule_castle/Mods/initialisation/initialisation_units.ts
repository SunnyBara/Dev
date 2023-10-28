import { Search_in_list } from "../Search/search_functions";
import { Base_stats, Units, State, Bar } from "../data/Unit";
import { boss_list, heros_list, trash_mobs_list } from "../data/importdata";

export function Typeunit(name: string) {
  if (Search_in_list(name, trash_mobs_list) !== undefined) {
    return "trash_mobs";
  } else if (Search_in_list(name, boss_list) !== undefined) {
    return "boss";
  } else if (Search_in_list(name, heros_list) !== undefined) {
    return "hero";
  } else {
    return "problèmes mon reuf";
  }
}

export function Create_unit(unit_Bs: Base_stats): Units {
  let unit_health: Bar = {
    current: unit_Bs.hp,
    max: unit_Bs.hp,
  };
  let unitstate: State = {
    health: unit_health,
  };
  if (unit_Bs.mp !== 0) {
    let unit_mana: Bar = {
      current: unit_Bs.mp,
      max: unit_Bs.mp,
    };
    unitstate.mana = unit_mana;
  }
  let unit_characteristrics = {
    str: unit_Bs.str,
    int: unit_Bs.int,
    def: unit_Bs.def,
    res: unit_Bs.res,
    spd: unit_Bs.spd,
    luck: unit_Bs.luck,
  };
  let newunit: Units = {
    name: unit_Bs.name,
    type: Typeunit(unit_Bs.name),
    base_stats: unit_Bs,
    state: unitstate,
    characteristics: unit_characteristrics,
  };
  return newunit;
}
