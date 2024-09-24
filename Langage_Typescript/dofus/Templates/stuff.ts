import { stats } from "./stats";

export class Stuff {
  public itemList: Item[] = [];
  constructor() {
    this.globalStat = new stats();
  }
  public globalStat: stats;
  calcGlobalStat() {
    for (const item in this.itemList) {
      for (const stat in this.globalStat) {
        this.globalStat[stat] += this.itemList[item].stats[stat];
      }
    }
  }

  additem(itemdb: Item, itemtype: string) {
    this.itemList[itemtype] = itemdb;
  }

  showGlobalStat() {
    console.log("/////////////GLOBAL STATS/////////");
    console.log(this.globalStat);
  }
  getGlobalStat() {
    return this.globalStat;
  }

  showStuff() {
    for (const item in this.itemList) {
      console.log(this.itemList[item]);
    }
  }
  showStuffName() {
    for (const item in this.itemList) {
      console.log(this.itemList[item].name);
    }
  }
}

export class Item {
  stats: stats;
  name: string;
  pano: boolean;
  panoname: string;
  type: string;
  constructor() {
    this.stats = new stats();
    this.pano = false;
  }
}

export enum Enumitem {
  Amulette = "12",
  Anneau = "13",
  Ceinture = "15",
  Chapeau = "16",
  Cape = "17-18",
  Bottes = "19",
}
