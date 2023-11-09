import { Units } from "../data/Unit";
import { combat_log } from "../initialisation/initialisation_tower";
import { Search_index_list } from "../Search/search_functions";

function Is_Dead(target_list: Units[], unit: Units) {
  target_list.splice(Search_index_list(target_list, unit), 1);
}

export function Kill_unit(target_list: Units[]) {
  let incr = 0 ;
  while( incr < target_list.length ) {
    if(target_list[incr].state.health.current <= 0 ) {
      combat_log.push(`${target_list[incr].name} is dead !`);
      Is_Dead(target_list, target_list[incr]);
      incr = -1;
    }
    incr += 1 ;
  }
  return;
}