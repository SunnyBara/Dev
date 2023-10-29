"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Choose_your_mods = exports.Switch_mods = exports.Manage_mod = exports.Mod_manager = void 0;
var importdata_1 = require("../data/importdata");
var start_1 = require("./start");
function Mod_manager(tower_rules) {
    var tab = ["Combat Option", "Characteristics Options"];
    var answers = importdata_1.rl.keyInSelect(tab, "Choose your Mods\nAll mods are disable by default", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        default:
            Set_up_mods(tower_rules, tab[answers]);
            break;
        case -1:
            (0, start_1.Menu)(tower_rules);
            return;
    }
    return;
}
exports.Mod_manager = Mod_manager;
function Set_up_mods(tower_rules, mod_name) {
    switch (mod_name.toLowerCase()) {
        case "combat option":
            console.log(tower_rules.better_combat_options.set
                ? "One or more options is currently active"
                : "Combats Options are currently disabled");
            break;
        case "characteristics options":
            console.log(tower_rules.basic_characteristics.set
                ? "One or more options is currently active"
                : "Characteristics options are currently disabled");
            break;
    }
    Manage_mod(tower_rules, mod_name);
}
function Manage_mod(tower_rules, mod_name) {
    var tab = [
        "Disable all ".concat(mod_name),
        "Active all ".concat(mod_name),
        "Choose",
    ];
    var answers = importdata_1.rl.keyInSelect(tab, "What do you want to do ?", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        case 0:
            Switch_mods(mod_name, false, tower_rules);
            break;
        case 1:
            Switch_mods(mod_name, true, tower_rules);
            break;
        case 2:
            Choose_your_mods(mod_name, tower_rules);
            break;
        case -1:
            Mod_manager(tower_rules);
            return;
    }
    return;
}
exports.Manage_mod = Manage_mod;
function Switch_mods(mod_name, change, tower_rules) {
    switch (mod_name) {
        case "characteristics options":
            tower_rules.basic_characteristics.character_creation = change;
            tower_rules.basic_characteristics.level_and_experience = change;
            tower_rules.basic_characteristics.basic_characteristics_II = change;
            break;
        case "combat option":
            tower_rules.better_combat_options.inventory = change;
            tower_rules.better_combat_options.magic_skills = change;
            tower_rules.better_combat_options.team_combat = change;
            break;
    }
    return;
}
exports.Switch_mods = Switch_mods;
function Choose_your_mods(mod_name, tower_rules) {
    switch (mod_name) {
        case "characteristics options":
            var mods = importdata_1.rl.keyInSelect([
                "character_creation",
                "level_and_experience",
                "basic_characteristics_II",
            ], "What do you want to do ?", {
                cancel: "Back to the menu",
            });
            switch (mods) {
                case 0:
                    tower_rules.basic_characteristics.character_creation =
                        !tower_rules.basic_characteristics.character_creation;
                    console.log("character_creation", tower_rules.basic_characteristics.character_creation
                        ? "is active"
                        : "is disable");
                    break;
                case 1:
                    tower_rules.basic_characteristics.level_and_experience =
                        !tower_rules.basic_characteristics.level_and_experience;
                    console.log("level_and_experience", tower_rules.basic_characteristics.level_and_experience
                        ? "is active"
                        : "is disable");
                    break;
                case 2:
                    tower_rules.basic_characteristics.basic_characteristics_II =
                        !tower_rules.basic_characteristics.basic_characteristics_II;
                    console.log("basic_characteristics_II", tower_rules.basic_characteristics.basic_characteristics_II
                        ? "is active"
                        : "is disable");
                    break;
                case -1:
                    Mod_manager(tower_rules);
                    return;
            }
            break;
        case "combat option":
            var answers = importdata_1.rl.keyInSelect(tab, "What do you want to do ?", {
                cancel: "Back to previous menu",
            });
            switch (answers) {
                case 0:
                    Switch_mods(mod_name, false, tower_rules);
                    break;
                case 1:
                    Switch_mods(mod_name, true, tower_rules);
                    break;
                case 2:
                    Choose_your_mods(mod_name, tower_rules);
                    break;
                case -1:
                    Mod_manager(tower_rules);
                    return;
            }
            break;
    }
    return;
}
exports.Choose_your_mods = Choose_your_mods;
