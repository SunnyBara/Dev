export interface Units {
  type: string;
  state: State;
  name: string;
  competence_list?: string[];
  base_stats: Base_stats;
  characteristics: Characteristics;
  fighting_status: Fighting_status;
}

export interface Fighting_status {
  fear: boolean;
  weakened: boolean;
  def_stance: boolean;
}

export interface Characteristics {
  str: number;
  int: number;
  def: number;
  res: number;
  spd: number;
  luck: number;
}

export interface Bar {
  current: number;
  max: number;
}

export interface State {
  health: Bar;
  mana?: Bar;
  level?: Bar;
}

export interface Level {
  exp: Bar;
  current_level: number;
}

export interface Base_stats {
  id: number;
  name: string;
  hp: number;
  mp: number;
  str: number;
  int: number;
  def: number;
  res: number;
  spd: number;
  luck: number;
  race: number;
  class: number;
  rarity: number;
}
