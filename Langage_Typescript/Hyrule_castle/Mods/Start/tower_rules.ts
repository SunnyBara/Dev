import { Characteristics_options, Combat_option, Mods, Tower_rules } from "../data/Tower"


export function Initiate_tower_rules() {
  let more_Statistics : Mods = {
    set : false,
    mod_name : 'more_Statistics'
  }
  let inventory : Mods = {
    set : false,
    mod_name : 'inventory'
  } 
  let magic_skills : Mods = {
    set : false,
    mod_name : 'magic_skills'
  } 
  let team_combat : Mods = {
    set : true,
    mod_name : 'team_combat'
  } 
  let character_creation : Mods = {
    set : false,
    mod_name : 'character_creation'
  } 
  let basic_characteristics_II : Mods = {
    set : false,
    mod_name : 'basic_characteristics_II'
  } 
  let level_and_experience : Mods = {
    set : false,
    mod_name : 'level_and_experience'
  }  
  let better_combat: Combat_option = {
    set: false,
    Combat_mods : [team_combat,more_Statistics,inventory,magic_skills],
  };
  let characteristics_options: Characteristics_options = {
    set: false,
    Characteristics_mods: [character_creation,basic_characteristics_II,level_and_experience]
  }
  
  let tower_rules: Tower_rules = {
    size: 100,
    difficultie: "",
    better_combat_options: better_combat,
    basic_characteristics: characteristics_options,
  };
  return tower_rules;
}
