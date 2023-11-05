"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Initiate_tower_rules = void 0;
function Initiate_tower_rules() {
    var more_Statistics = {
        set: false,
        mod_name: 'more_Statistics'
    };
    var inventory = {
        set: false,
        mod_name: 'inventory'
    };
    var magic_skills = {
        set: false,
        mod_name: 'magic_skills'
    };
    var team_combat = {
        set: true,
        mod_name: 'team_combat'
    };
    var character_creation = {
        set: false,
        mod_name: 'character_creation'
    };
    var basic_characteristics_II = {
        set: false,
        mod_name: 'basic_characteristics_II'
    };
    var level_and_experience = {
        set: false,
        mod_name: 'level_and_experience'
    };
    var better_combat = {
        set: false,
        Combat_mods: [team_combat, more_Statistics, inventory, magic_skills],
    };
    var characteristics_options = {
        set: false,
        Characteristics_mods: [character_creation, basic_characteristics_II, level_and_experience]
    };
    var tower_rules = {
        size: 100,
        difficultie: "",
        better_combat_options: better_combat,
        basic_characteristics: characteristics_options,
    };
    return tower_rules;
}
exports.Initiate_tower_rules = Initiate_tower_rules;
