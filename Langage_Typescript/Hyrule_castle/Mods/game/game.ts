import { Tower } from "../data/Tower";
import { Units } from "../data/Unit";
import { hero_list } from "../initialisation/initialisation_hero";
import { Build_fight_list, Set_up_initiative } from "./Set_up_floor";
import { Action } from "../Actions/action";
import Begin_of_turn from "./being_of_turn";

export default function Game(tower: Tower): boolean {
  let keep_playing: boolean = true;
  let cpt = 0;
  while (tower.nbr_floor > tower.current_floor && keep_playing === true) {
    const fight_list: Units[] = Build_fight_list(
      tower.floors[tower.current_floor].ennemies
    );
    const initiative_list: Units[] = Set_up_initiative(fight_list, hero_list);
    cpt = 0 ;
    while (fight_list.length > 0 && keep_playing === true) {
      console.clear();
      Begin_of_turn(fight_list, tower,cpt);
      cpt += 1;
      keep_playing = Action(initiative_list, fight_list, tower);
    }
    tower.current_floor += 1;
  }
  return keep_playing;
}
