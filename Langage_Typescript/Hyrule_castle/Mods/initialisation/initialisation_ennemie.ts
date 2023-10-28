import { Search_in_ennemie_list } from "../Search/search_functions";
import { Rarity_list } from "../data/Tower";
import { Units } from "../data/Unit";
import { Create_unit } from "./initialisation_units";

export function Init_ennemie_list(
  nbr_ennemie: number,
  ennemies: Rarity_list
): string[] {
  let ennemie_at_this_floor: string[] = [];
  let incr: number = 0;
  while (incr < nbr_ennemie) {
    ennemie_at_this_floor.push(
      ennemies.list[Math.floor(Math.random() * ennemies.list.length)]
    );
    incr += 1;
  }
  return ennemie_at_this_floor;
}

export function Create_ennemie_fighter(ennemie_name: string): Units {
  let ennemiestats = Search_in_ennemie_list(ennemie_name);
  let newennemie: Units = Create_unit(ennemiestats);
  return newennemie;
}

export function Add_fighter(ennemie: Units, fight_list: Units[]) {
  fight_list.push(ennemie);
  return;
}
