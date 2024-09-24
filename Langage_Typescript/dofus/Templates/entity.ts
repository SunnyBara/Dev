import { Damage } from "../CalculDamages/calculDamge";
import { InterfaceSorts, Sorts } from "./sorts";
import { stats } from "./stats";
import { Stuff } from "./stuff";
const fs = require("fs");

export class Entity {
  public baseStats: stats;
  public stats: stats;
  public sorts: Sorts[];
  public level: number;
  public path: string;
  constructor(level: number) {
    this.level = level;
    this.sorts = [];
  }

  public buildspell(spellInformation: InterfaceSorts) {
    const spell = new Sorts(
      spellInformation.normaldamages.min,
      spellInformation.normaldamages.max,
      spellInformation.critdamages.min,
      spellInformation.critdamages.max
    );
    spell.nom = spellInformation.nom;
    spell.critchance = spellInformation.critchance;
    spell.element = spellInformation.element;
    this.sorts.push(spell);
  }

  public implementEntity() {
    const file = fs.readFileSync(this.path);
    const content = JSON.parse(file);
    const build = this.findlvlbuild(content);
    this.setbaseStat(build["stats"]);
    this.buildStat(undefined);
    for (const spell of build["sort"]) {
      const spellInterface: InterfaceSorts = {
        nom: spell["nom"],
        normaldamages: spell["damages"]["normal"],
        critdamages: spell["damages"]["crit"],
        critchance: spell["critchance"],
        cout: spell["cout"],
        use: spell["use"],
        element: spell["element"],
      };
      this.buildspell(spellInterface);
    }
  }

  public findlvlbuild(listlevel) {
    for (const build of listlevel) {
      if (build["lvl"] == this.level) {
        return build;
      }
    }
  }

  public setbaseStat(buildstats) {
    const stat = new stats();
    for (const buildstat in buildstats) {
      stat[buildstat] = buildstats[buildstat];
    }
    this.baseStats = stat;
  }

  public buildStat(stuff: Stuff | undefined) {
    const stat = new stats();
    let stuffglobalstat: stats | undefined = undefined;
    if (stuff) {
      stuffglobalstat = stuff.getGlobalStat();
    }
    for (const nameOfStat in this.baseStats) {
      stat[nameOfStat] = this.baseStats[nameOfStat];
      if (stuffglobalstat !== undefined) {
        stat[nameOfStat] += stuffglobalstat[nameOfStat];
      }
    }
    this.stats = stat;
  }

  public showspelllist() {
    for (const spell of this.sorts) {
      console.log(spell);
    }
  }
  public showStates() {
    console.log(this.stats);
  }
  public spelldamages() {
    for (const sort of this.sorts) {
      console.log(
        `spell ${sort.nom} : ${Damage.damage(
          this.stats,
          sort.normaldamages.moyen,
          sort.element
        )}`
      );
      console.log(
        `spell crit ${sort.nom} : ${Damage.damage(
          this.stats,
          sort.critdamages.moyen,
          sort.element
        )}`
      );
    }
  }
}
