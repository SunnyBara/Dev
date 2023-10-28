import { Floor, Tower } from "../data/Tower";
import { Towertemplate } from "../data/inittower";
import { Random_rarirty } from "../data/random";
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
      newfloor.current_floor = incr;
      newfloor.ennemies = Init_ennemie_list(
        tower.rules?.teams,
        tower.trash_mobs[Random_rarirty()]
      );
    } else {
      newfloor.current_floor = incr;
      newfloor.ennemies = Init_ennemie_list(
        tower.rules?.teams - 1,
        tower.trash_mobs[Random_rarirty()]
      );
      newfloor.ennemies = Init_ennemie_list(1, tower.boss[Random_rarirty()]);
    }
    incr += 1;
    tower.floors.push(newfloor);
  }
  return tower;
}

export let combat_log: string[] = [];
