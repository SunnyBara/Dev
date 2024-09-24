import { stats } from "../Templates/stats";

export class Damage {
  public static damage(
    stats: stats,
    baseDamage: number,
    element: string
  ): number {
    const elementToHit = Damage.chooseElem(stats, element);
    let damage: number = Math.floor(
      baseDamage +
        baseDamage * ((stats.DommagePercent + elementToHit) / 100) +
        stats.Dommage
    );
    return damage;
  }
  private static chooseElem(stat: stats, element: string) {
    let elementChoosen: number;
    switch (element) {
      case "Best":
        let compare1: number;
        let compare2: number;
        compare1 = stat.Force > stat.Chance ? stat.Force : stat.Chance;
        compare2 =
          stat.Intelligence > stat.Agilité ? stat.Intelligence : stat.Agilité;
        elementChoosen = compare1 > compare2 ? compare1 : compare2;
        break;
      default:
        elementChoosen = stat[element];
    }
    return elementChoosen;
  }
}
