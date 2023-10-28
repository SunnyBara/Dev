import { Search_in_Hero_list } from "../Search/search_functions";
import { Units } from "../data/Unit";
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
