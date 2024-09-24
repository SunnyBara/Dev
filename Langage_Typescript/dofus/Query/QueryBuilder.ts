import { stats } from "../Templates/stats";
import { Enumitem, Item } from "../Templates/stuff";

const axios = require("axios");
export class QueryBuilder {
  query: string;
  base_url: string;
  levelmax: String;
  levelmin: String;
  context: String;
  slot: String;
  constructor() {
    this.levelmin = "180";
    this.levelmax = "190";
    this.base_url = "https://retro.dofusbook.net/items/retro/search/";
    this.slot = "";
  }

  async buildQuery() {
    this.query = this.base_url;
    this.query += `${this.context}`;
    this.query += `&level_min=${this.levelmin}`;
    this.query += `&level_max=${this.levelmax}`;
    this.query += this.slot;
    this.query += "&page=1&sort=desc";
  }

  findItem(item: string) {
    this.context = "equipment?context=item";
    this.slot = `&include=${item}`;
    return this;
  }

  findWeapon() {
    this.slot = "";
    this.context = "weapon?context=weapon";
    return this;
  }
  async execQuery() {
    await this.buildQuery();
    console.log(this.query);
    const itemList: Item[] = [];
    await axios.get(this.query).then((Response) => {
      for (const items of Response.data.data) {
        console.log(items.name);
        const item = new Item();
        const itemFormatted = this.formatItem(items);
        if (items.cloth_name) {
          item.pano = true;
          item.panoname = items.cloth_name;
        }
        item.stats = itemFormatted.stats;
        item.name = items.name;
        item.type = itemFormatted.type;
        itemList.push(item);
      }
    });
    return itemList;
  }

  formatItem(item) {
    const itemdb = {
      stats: this.formatItemStat(item.effects),
      type: item.category_name,
    };
    return itemdb;
  }
  formatItemStat(effects): stats {
    const itemdb = new stats();
    for (const effect of effects) {
      switch (effect.name) {
        case "ch":
          itemdb.Chance = effect.max;
          break;
        case "in":
          itemdb.Intelligence = effect.max;
          break;
        case "pa":
          itemdb.Ap = effect.max;
          break;
        case "dmg":
          itemdb.Dommage = effect.max;
          break;
        case "pu":
          itemdb.DommagePercent = effect.max;
          break;
        case "fo":
          itemdb.Force = effect.max;
          break;
        case "ag":
          itemdb.Agilité = effect.max;
          break;
      }
    }
    return itemdb;
  }
}
export const queryBuilder = new QueryBuilder();
