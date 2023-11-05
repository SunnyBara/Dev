import { Tower, Tower_rules } from "../data/Tower";
import { boss_list, trash_mobs_list } from "../data/importdata";
import { Set_up_rarity_units } from "./Initialisation_rarity";

export let Towertemplate = new  Tower();

export function Initiate_tower(tower_rules: Tower_rules) {
    Towertemplate.floors = [];
    Towertemplate.nbr_floor = tower_rules.size;
    Towertemplate.current_floor = 0;
    Towertemplate.boss = Set_up_rarity_units(boss_list);
    Towertemplate.trash_mobs = Set_up_rarity_units(trash_mobs_list);
    Towertemplate.tower_rules = tower_rules;
  }
  