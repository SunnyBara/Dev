import { Search_in_Hero_list } from "../Search/search_functions";
import { Tower_rules } from "../Start/tower_rules";
import { Rarity_list } from "../data/Tower";
import { Units } from "../data/Unit";
import { heros_list } from "../data/importdata";
import { Random_hero, Random_rarirty } from "../data/random";
import { Set_up_rarity_units } from "./Initialisation_rarity";
import { Create_unit } from "./initialisation_units";

export const hero_list: Units[] = [];

export function Create_hero(hero_name: string): Units {
  let herostats = Search_in_Hero_list(hero_name);
  let newhero: Units = Create_unit(herostats);
  return newhero;
}

export function Add_hero(hero: Units) {
  hero_list.push(hero);
  return;
}

export function Init_hero(tower_rules: Tower_rules) {
  let hero: number[] = [];
  let avaible_hero_list: number[] = [1, 2, 3, 4, 5];
  hero.push(Random_hero(avaible_hero_list));
  if (tower_rules.better_combat_options.team_combat) {
  }
  let set_up_hero_rarity: Rarity_list[] = Set_up_rarity_units(heros_list);
  while (hero.length > 0) {
    Create_hero(
      set_up_hero_rarity[hero[0]].list[
        Math.floor(Math.random() * set_up_hero_rarity[hero[0]].list.length)
      ]
    );
  }
}
