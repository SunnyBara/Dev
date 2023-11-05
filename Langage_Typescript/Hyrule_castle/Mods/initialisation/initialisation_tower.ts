import { findIfModIsActive } from "../Start/Set_mods";
import { Floor, Tower } from "../data/Tower";
import { Random_rarity} from "../data/random";
import { Towertemplate } from "./init_tower_template";
import { Init_ennemie_list } from "./initialisation_ennemie";

export function Testfloor(current_floor: number, regex: RegExp): boolean {
  let cr = true;
  if (String(current_floor).match(regex)) {
    cr = false;
  }
  return cr;
}

export function Initiat_floor(): Tower {
  let incr: number = 1;
  let teamsize = 1;
  if(findIfModIsActive('team_combat')){
    teamsize = 4;
  }
  while (incr <= Towertemplate.nbr_floor) {
    let newfloor: Floor = {
      current_floor: 0,
      ennemies: [],
    };
    if (Testfloor(incr, /\d+0/)) {
      newfloor.current_floor = incr;
      newfloor.ennemies = Init_ennemie_list(teamsize,
        Towertemplate.trash_mobs[Random_rarity()]
      );
    } else {
      let random_boss = Random_rarity();
      while(Towertemplate.boss[random_boss].list.length === 0)
      {
        random_boss = (((random_boss + 1) % 5) + 1); 
      }
      const boss_name : string[] = Init_ennemie_list(1, Towertemplate.boss[random_boss]);
      Towertemplate.boss[random_boss].list.splice(Towertemplate.boss[random_boss].list.indexOf(boss_name[0]),1);
      newfloor.current_floor = incr;
      newfloor.ennemies = Init_ennemie_list(
        teamsize - 1,
        Towertemplate.trash_mobs[Random_rarity()]
      );
      newfloor.ennemies.push(boss_name[0]);
          }
    incr += 1;
    Towertemplate.floors.push(newfloor);
  }
  return Towertemplate;
}

export let combat_log: string[] = [];
