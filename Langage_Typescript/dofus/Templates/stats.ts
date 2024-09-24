export class stats {
  public Force: number;
  public Agilité: number;
  public Intelligence: number;
  public Chance: number;
  public Dommage: number;
  public DommagePercent: number;
  public Ap: number;
  constructor() {
    this.Force = 0;
    this.Agilité = 0;
    this.Intelligence = 0;
    this.Chance = 0;
    this.Dommage = 0;
    this.DommagePercent = 0;
    this.Ap = 0;
  }
}

export enum statsEnum {
  Chance = "160_1",
  Intelligence = "150_1",
  Force = "140_1",
  Agilité = "170_1",
  DommagePercent = "190_1",
}

// Exemple :
// chance : https://retro.dofusbook.net/items/retro/search/equipment?context=item&effect=160_1&include=12&page=1&sort=desc
// intel : URL: https://retro.dofusbook.net/items/retro/search/equipment?context=item&effect=150_1&include=12&page=1&sort=desc
// chance + intel : https://retro.dofusbook.net/items/retro/search/equipment?context=item&effect=150_1.160_1&include=12&page=1&sort=desc

// chance :effect=160_1
// intel :effect=150_1
// force :effect=140_1
// agi:  effect = 170_1
// %dommage: effect=190_1

//("base url https://retro.dofusbook.net/items/retro/search/equipment?context=item&page=1&sort=desc");
