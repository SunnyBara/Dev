import { Base_stats, Units } from "../data/Unit";
import {
  boss_list,
  classes_list,
  heros_list,
  trash_mobs_list,
} from "../data/importdata";

export function Search_index_list(list: Units[], unit: Units) {
  let i: number = 0;
  while (list[i] != unit) {
    i += 1;
  }
  return i;
}

export function Search_in_Hero_list(hero_name: string): Base_stats {
  return Search_in_list(hero_name, heros_list);
}

export function Search_in_ennemie_list(ennemie_name: string): Base_stats {
  let ennemie: Base_stats = Search_in_list(ennemie_name, trash_mobs_list);
  if (ennemie === undefined) {
    ennemie = Search_in_list(ennemie_name, boss_list);
  }
  return ennemie;
}

export function Search_in_list(ennemie_name: string, list: any[]): any {
  let incr: number = 0;
  while (list[incr] !== undefined && list[incr].name !== ennemie_name) {
    incr += 1;
  }
  return list[incr];
}

export function Search_class_advantage(
  list_advantage: number[],
  target_id: number
): boolean {
  let incr: number = 0;
  while (
    list_advantage[incr] !== undefined &&
    list_advantage[incr] !== target_id
  ) {
    incr += 1;
  }
  if (list_advantage[incr] !== undefined) {
    return true;
  }
  return false;
}

export function Search_race_advantage(
  list_advantage: number[],
  target_id: number
): boolean {
  let incr: number = 0;
  while (
    list_advantage[incr] !== undefined &&
    list_advantage[incr] !== target_id
  ) {
    incr += 1;
  }
  if (list_advantage[incr] !== undefined) {
    return true;
  }
  return false;
}

export function Search_class(id_classe: number) {
  let incr: number = 0;
  while (
    classes_list[incr].id !== undefined &&
    classes_list[incr].id !== id_classe
  ) {
    incr += 1;
  }
  return classes_list[incr];
}

export function Name_from_list(list: Units[]): string[] {
  let names: string[] = [];
  for (const unit of list) {
    names.push(unit.name);
  }
  return names;
}
