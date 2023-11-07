import { Damages } from "../data/Damages";
import { Units } from "../data/Unit";

export function Add_Damages_combat_log(
  target: Units,
  unit: Units,
  damage: Damages,
  combat_log: string[]
) {
  if (damage.Crushing) {
    combat_log.push("Crushing hit !");
  } else if (damage.Glancing) {
    combat_log.push("Glancing hit ...");
  }
  if (damage.damages > 0)
    combat_log.push(
      damage.Crit
        ? `${unit.name} CRITS ${target.name} FOR  ${Math.floor(damage.damages)} DAMAGES ! `
        : `${unit.name} deals ${Math.floor(damage.damages)} to ${target.name}`
    );
  else {
    if (target === unit) {
      combat_log.push(
        damage.Crit
          ? `${unit.name} HEALS CRIT HIMSELF FOR ${-Math.floor(damage.damages)} !`
          : `${unit.name} heals himself ${-Math.floor(damage.damages)}Hp`
      );
    } else {
      combat_log.push(
        damage.Crit
          ? `${unit.name} HEALS CRIT ${target.name} FOR  ${-Math.floor(damage.damages)} !`
          : `${unit.name} heals ${target.name}  ${-Math.floor(damage.damages)}Hp`
      );
    }
  }
  return;
}

export function Display_Combat_log(combat_log: string[]) {
  console.log(`previous turn logs \n`);
  for (const log of combat_log) {
    console.log(log);
  }
  return;
}

export function Reset_combat_log(combat_log: string[]) {
  while (combat_log.length > 0) {
    combat_log.pop();
  }
}
