export interface Tower {
  nbr_floor: number;
  current_floor: number;
  trash_mobs: string[];
  boss: string[];
  floors: Floor[];
}

export interface Floor {
  current_floor: number;
  ennemies: string[];
}
