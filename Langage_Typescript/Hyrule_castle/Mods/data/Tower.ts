export class Tower {
  nbr_floor: number;
  current_floor: number;
  trash_mobs: Rarity_list[];
  boss: Rarity_list[];
  floors: Floor[];
  tower_rules : Tower_rules;
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
  damage_modifiers : boolean;

}
export interface Tower_rules {
  size: number;
  difficultie: string;
  better_combat_options: Combat_option;
  basic_characteristics: Characteristics_options;
}
export interface Combat_option {
  set: boolean;
  Combat_mods : Mods[];
}
export interface Characteristics_options {
  set: boolean;
  Characteristics_mods : Mods[];
}

export interface Mods {
  mod_name : string,
  set : boolean,
}
