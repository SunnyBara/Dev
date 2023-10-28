import { Rarity_list } from "../data/Tower";

export function Set_up_rarity_units(list: any[]): Rarity_list[] {
  let my_rarity_tab: Rarity_list[] = [];
  let incr: number = 0;
  let parcours: number = 0;
  while (incr < 6) {
    parcours = 0;
    let new_rarity_list: Rarity_list = {
      rarity: 0,
      list: [],
    };
    let new_string_list: string[] = [];
    while (list[parcours] !== undefined) {
      if (list[parcours].rarity === incr) {
        new_string_list.push(list[parcours].name);
      }

      parcours += 1;
    }
    new_rarity_list.list = new_string_list;
    new_rarity_list.rarity = incr;
    my_rarity_tab.push(new_rarity_list);
    incr += 1;
  }
  return my_rarity_tab;
}
