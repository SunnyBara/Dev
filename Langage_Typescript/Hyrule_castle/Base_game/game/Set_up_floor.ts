import { Units } from "../data/Unit";
import { Create_ennemie_fighter } from "../initialisation/initialisation_ennemie";

export function Build_fight_list(ennemie_list: string[]): Units[] {
  const fight_list: Units[] = [];
  for (const ennemie of ennemie_list) {
    fight_list.push(Create_ennemie_fighter(ennemie));
  }
  return fight_list;
}

export function Set_up_initiative(
  hero_list: Units[],
  fight_list: Units[]
): Units[] {
  const initiative_list: Units[] = [hero_list[0], fight_list[0]];
  return initiative_list;
}
