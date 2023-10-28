import { Tower_rules } from "../Start/tower_rules";
import { Set_up_rarity_units } from "../initialisation/Randoms";
import { Tower } from "./Tower";
import { boss_list, trash_mobs_list } from "./importdata";

export let Towertemplate: Tower = {
  nbr_floor: 10,
  current_floor: 0,
  trash_mobs: [],
  boss: [],
  floors: [],
};

export function Initiate_tower(tower_rules: Tower_rules) {
  Towertemplate.nbr_floor = tower_rules.size;
  Towertemplate.boss = Set_up_rarity_units(boss_list);
  Towertemplate.trash_mobs = Set_up_rarity_units(trash_mobs_list);
}
