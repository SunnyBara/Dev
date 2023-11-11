import { Item } from "../data/Iventory";
import { Units } from "../data/Unit";
import { Random_rarity } from "../data/random";
import { hero_list, inventory } from "../initialisation/initialisation_hero";
import { combat_log } from "../initialisation/initialisation_tower";

export function End_of_fight(){
    give_xp();
    give_loot();
}

export function give_loot() {
    let loot : Item = {
        Description :"",
        name : "",
        count : 1
    }
    switch(Random_rarity()) {
        case 1:
          loot.name = "Low-level Potion"
          loot.Description = "Restaure 10% of your health and 10 mana"
        break;
        case 2:
          loot.name = "Potion"
          loot.Description = "Restaure 25% of your health and 20 mana"
        break;
        case 3:
          loot.name = "Good Potion"
          loot.Description = "Restaure 35% of your health and 25 mana"
        break;
        case 4:
            loot.name = "High-level Potion"
            loot.Description = "Restaure 50% of your health and 50 mana"
        break;
        case 5:
            loot.name = "Holy Potion"
            loot.Description = "Restaure 100% of your health, 100% mana and give 500xp"
        break;
    }
    combat_log.push(`You loot a ${loot.name}`);
    inventory.add(loot);
}


export function give_xp(){
  hero_list.forEach(hero => {
    if(hero.state.level !== undefined) {
      hero.state.level.exp.current += Math.floor((Math.random()*38) + 12);
      Is_level_up(hero);
    }
  });
}

export function Is_level_up(hero:Units)
{
  if(hero.state.level !== undefined) {
    if(hero.state.level.exp.current >= hero.state.level.exp.max) {
      level_up(hero);
      combat_log.push(`${hero.name} à level up au niveau ${hero.state.level.current_level}`);
    }     
  }   
}

export function level_up(hero : Units) {
    hero.characteristics.def += Math.floor(hero.characteristics.def*0.05) 
    hero.characteristics.str += Math.floor(hero.characteristics.str*0.05) 
    hero.characteristics.int += Math.floor(hero.characteristics.int*0.05) 
    hero.characteristics.luck += Math.floor(hero.characteristics.luck*0.05) 
    hero.characteristics.res += Math.floor(hero.characteristics.res*0.05) 
    hero.characteristics.spd += Math.floor(hero.characteristics.spd*0.05) 
    hero.state.health.max += Math.floor(hero.state.health.max*0.05) 
    if(hero.state.mana !== undefined) {
      hero.state.mana.max += Math.floor(hero.state.mana.max *0.05) 
    }
    if(hero.state.level) {   
      hero.state.level.current_level += 1 ;
      hero.state.level.exp.current -= Math.floor(hero.state.level.exp.max);
      hero.state.level.exp.max += Math.floor(hero.state.level.exp.max * 0.2);
    }
}