import { Units } from "../data/Unit";
import { Towertemplate } from "../initialisation/init_tower_template";
import { Create_ennemie_fighter } from "../initialisation/initialisation_ennemie";

export function Build_fight_list(ennemie_list: string[]): Units[] {
  const fight_list: Units[] = [];
  for (const ennemie of ennemie_list) {
    fight_list.push(Create_ennemie_fighter(ennemie,Towertemplate.tower_rules));
  }
  return fight_list;
}

export function Set_up_initiative(
  hero_list: Units[],
  fight_list: Units[]
): Units[] {
  const initiative_list = init_innerlist([hero_list,fight_list]);
  return initiative_list;
}

export function init_innerlist(lists: Units[][]) :Units[] {
  const init_list : Units[] = [];
  for (const list of lists) {
    list.forEach((unit) => {
      init_list.push(unit);
    })
  }
  init_list.sort((a ,b) => {
    return(b.base_stats.spd - a.base_stats.spd)
  });
  return(init_list)
}