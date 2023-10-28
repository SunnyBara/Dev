export interface Tower_rules {
  size: number;
  difficultie: string;
  better_combat_options: Combat_option;
  basic_characteristics: Characteristics_options;
}
export interface Combat_option {
  set: boolean;
  more_Statistics: boolean;
  inventory: boolean;
  magic_skills: boolean;
  team_combat: boolean;
}
export interface Characteristics_options {
  set: boolean;
  character_creation: boolean;
  basic_characteristics_II: boolean;
  level_and_experience: boolean;
}

export function Initiate_tower_rules() {
  let better_combat: Combat_option = {
    set: false,
    more_Statistics: false,
    inventory: false,
    magic_skills: false,
    team_combat: false,
  };
  let characteristics_options: Characteristics_options = {
    set: false,
    character_creation: false,
    basic_characteristics_II: false,
    level_and_experience: false,
  };

  let tower_rules: Tower_rules = {
    size: 0,
    difficultie: "",
    better_combat_options: better_combat,
    basic_characteristics: characteristics_options,
  };
  return tower_rules;
}
