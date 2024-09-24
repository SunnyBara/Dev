export class Sorts {
  public nom: string;
  public normaldamages: damagesSpells;
  public critdamages: damagesSpells;
  public critchance: number;
  public cout: number;
  public use: number;
  public element: string;

  constructor(
    normalmin: number,
    normalmax: number,
    critmin: number,
    critmax: number
  ) {
    this.normaldamages = new damagesSpells(normalmin, normalmax);
    this.critdamages = new damagesSpells(critmin, critmax);
  }
}

export class damagesSpells {
  public min: number;
  public max: number;
  public moyen: number;
  constructor(min: number, max: number) {
    this.min = min;
    this.max = max;
    this.calcmoy();
  }
  private calcmoy() {
    this.moyen = Math.floor((this.min + this.max) / 2);
  }
}
export interface InterfaceSorts {
  nom: string;
  normaldamages: damagesSpells;
  critdamages: damagesSpells;
  critchance: number;
  cout: number;
  use: number;
  element: string;
}
