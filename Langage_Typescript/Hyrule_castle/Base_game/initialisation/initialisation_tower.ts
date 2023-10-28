import { Floor, Tower } from "../data/Tower";
import { Towertemplate } from "../data/inittower";
import { Init_ennemie_list } from "./initialisation_ennemie";

function Testfloor(current_floor: number, regex: RegExp): boolean {
  let cr = true;
  if (String(current_floor).match(regex)) {
    cr = false;
  }
  return cr;
}

export function Initiat_floor(): Tower {
  let incr: number = 1;
  let tower: Tower = Towertemplate;
  while (incr <= tower.nbr_floor) {
    let newfloor: Floor = {
      current_floor: 0,
      ennemies: [],
    };
    if (Testfloor(incr, /\d+0/)) {
      (newfloor.current_floor = incr),
        (newfloor.ennemies = Init_ennemie_list(1, tower.trash_mobs));
    } else {
      (newfloor.current_floor = incr),
        (newfloor.ennemies = Init_ennemie_list(1, tower.boss));
    }
    incr += 1;
    tower.floors.push(newfloor);
  }
  return tower;
}

export let combat_log: string[] = [];
