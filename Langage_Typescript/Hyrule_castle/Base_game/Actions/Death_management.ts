import { Units } from "../data/Unit";
import { combat_log } from "../initialisation/initialisation_tower";
import { Search_index_list } from "../Search/search_functions";

export function Is_it_dead(target_list: Units[], unit: Units) {
  if (unit.state.health.current <= 0) {
    combat_log.push(`${unit.name} is dead !`);
    Is_Dead(target_list, unit);
  }
  return unit;
}

function Is_Dead(target_list: Units[], unit: Units) {
  target_list.splice(Search_index_list(target_list, unit), 1);
}
