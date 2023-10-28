export interface Tower {
  nbr_floor: number;
  current_floor: number;
  trash_mobs: Rarity_list[];
  boss: Rarity_list[];
  floors: Floor[];
  rules?: Rules;
}

export interface Floor {
  current_floor: number;
  ennemies: string[];
}

export interface Rarity_list {
  rarity: number;
  list: string[];
}

export interface Rules {
  teams: number;
}
