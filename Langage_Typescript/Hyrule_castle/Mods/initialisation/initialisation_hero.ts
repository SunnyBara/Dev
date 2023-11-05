import { Search_in_Hero_list } from "../Search/search_functions";
import { findIfModIsActive } from "../Start/Set_mods";
import { Rarity_list, Tower_rules } from "../data/Tower";
import { Units } from "../data/Unit";
import { heros_list } from "../data/importdata";
import { Random_hero } from "../data/random";
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

export function Init_hero() {
  let hero: number[] = [];
  let teamsize = 1;
  if (findIfModIsActive('team_combat')) {
    teamsize = 4;
  }
  let avaible_hero_list: number[] = [1,2,3,4,5];
  while(teamsize > 0)
  {
    hero.push(Random_hero(avaible_hero_list));
    teamsize -=1;
  }
  let set_up_hero_rarity: Rarity_list[] = Set_up_rarity_units(heros_list);
    for(const rarity of hero) {
      for(const hero of set_up_hero_rarity) {
        if(rarity === hero.rarity ){
          Add_hero(Create_hero(hero.list[0]));
        }
     }
    }  
 }
