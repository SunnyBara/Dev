import { Units } from "../data/Unit";
import { hero_list } from "../initialisation/initialisation_hero";
import { combat_log } from "../initialisation/initialisation_tower";
import { Display_Combat_log } from "./display_damages";

function Calcul_health_bar(percentage_health: number): string {
  let HealthBar: string = "/";
  let incr = 0;
  while (incr < percentage_health) {
    if (incr % 10 === 0) {
      HealthBar += "/";
    } else {
      HealthBar += " ";
    }
    incr += 1;
  }
  return HealthBar;
}

export default function Displayfighters(
  fight_list: Units[],
  hero_list: Units[]
) {
  for (const ennemie of fight_list) {
    const HealthBar = Calcul_health_bar(
      Math.floor(
        (ennemie.state.health.current / ennemie.state.health.max) * 100
      )
    );
    console.log(`\u001b[37;46;40m${ennemie.name}`);
    console.log("\u001b[30;46;41m" + HealthBar + "\u001b[37;46;40m");
    console.log(
      `Hp : ${ennemie.state.health.current}/${ennemie.state.health.max}`,
      ennemie.state.mana
        ? `\nMana : ${ennemie.state.mana.current}/${ennemie.state.mana.max}`
        : ""
    );
  }
  for (const hero of hero_list) {
    const HealthBar = Calcul_health_bar(
      Math.floor((hero.state.health.current / hero.state.health.max) * 100)
    );
    console.log(`${hero.name}`, hero.state.level ? ` lv ${hero.state.level.current_level}`: ``);
    console.log("\u001b[37;46;42m" + HealthBar + "\u001b[37;46;40m");

    console.log(
      `Hp : ${hero.state.health.current}/${hero.state.health.max}`,
      hero.state.mana
        ? `\nMana : ${hero.state.mana.current}/${hero.state.mana.max}`
        : ""
      ,hero.state.level
        ? `\nExp : ${hero.state.level.exp.current}/${hero.state.level.exp.max}`
        : ""
    );
  }
}

export function Display_Floor(current_floor: number) {
  console.log(`CURRENT FLOOR ${current_floor}\n`);

  return;
}

export function Display(fight_list: Units[], current_floor: number) {
  Display_Floor(current_floor);
  Displayfighters(fight_list, hero_list);
  console.log(`\n`);
  if (combat_log.length > 0) {
    Display_Combat_log(combat_log);
  }
}
