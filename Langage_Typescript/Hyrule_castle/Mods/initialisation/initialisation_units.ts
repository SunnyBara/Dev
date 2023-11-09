import { Search_in_list } from "../Search/search_functions";
import { Base_stats, Units, State, Bar, Fighting_status } from "../data/Unit";
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
  if(unit_Bs.statsmultiplier === undefined)
  {
    unit_Bs.statsmultiplier = 1;
  }
  let unit_health: Bar = {
    current: unit_Bs.hp*unit_Bs.statsmultiplier,
    max: unit_Bs.hp*unit_Bs.statsmultiplier,
  };
  let fightstats : Fighting_status = {
    fear : false,
    def_stance : false,
    weakened : false
  }
  
  let unitstate: State = {
    health: unit_health,
  };
  if (unit_Bs.mp !== 0) {
    let unit_mana: Bar = {
      current: unit_Bs.mp*unit_Bs.statsmultiplier,
      max: unit_Bs.mp*unit_Bs.statsmultiplier,
    };
    unitstate.mana = unit_mana;
  }

  let unit_characteristrics = {
    str: unit_Bs.str*unit_Bs.statsmultiplier,
    int: unit_Bs.int*unit_Bs.statsmultiplier,
    def: unit_Bs.def*unit_Bs.statsmultiplier,
    res: unit_Bs.res*unit_Bs.statsmultiplier,
    spd: unit_Bs.spd*unit_Bs.statsmultiplier,
    luck: unit_Bs.luck*unit_Bs.statsmultiplier,
  };
  let newunit: Units = {
    name: unit_Bs.name,
    type: Typeunit(unit_Bs.name),
    base_stats: unit_Bs,
    state: unitstate,
    characteristics: unit_characteristrics,
    fighting_status : fightstats
  };
  return newunit;
}
