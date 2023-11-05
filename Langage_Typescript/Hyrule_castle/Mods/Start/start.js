"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Menu = exports.Start = void 0;
var importdata_1 = require("../data/importdata");
var initialisation_1 = require("../initialisation/initialisation");
var Set_mods_1 = require("./Set_mods");
var tower_rules_1 = require("./tower_rules");
var game_1 = require("../game/game");
var End_1 = require("../End/End");
function Start() {
    var tower_rules = (0, tower_rules_1.Initiate_tower_rules)();
    Menu(tower_rules);
    return;
}
exports.Start = Start;
function Menu(tower_rules) {
    console.clear();
    var tab = ["New game", "Optionnal Mods"];
    var answers = importdata_1.rl.keyInSelect(tab, "Welcome !", {
        cancel: "Quit",
    });
    switch (answers) {
        case 0:
            Set_up_game_rules(tower_rules);
            break;
        case 1:
            (0, Set_mods_1.Mod_manager)(tower_rules);
            break;
        case -1:
            return;
    }
    return;
}
exports.Menu = Menu;
function Set_up_game_rules(tower_rules) {
    console.clear();
    var tab = ["Normal", "Difficult", "Insane"];
    var answers = importdata_1.rl.keyInSelect(tab, "Choose your difficultie", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        default:
            tower_rules.difficultie = tab[answers];
            break;
        case -1:
            Menu(tower_rules);
    }
    Choose_size_of_tower(tower_rules);
    return;
}
function Choose_size_of_tower(tower_rules) {
    console.clear();
    var tab = ["10", "20", "50", "100"];
    var answers = importdata_1.rl.keyInSelect(tab, "Choose your difficultie", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        default:
            tower_rules.size = parseInt(tab[answers]);
            break;
        case -1:
            Set_up_game_rules(tower_rules);
            return;
    }
    console.log(tower_rules);
    Ready_to_start(tower_rules);
    return;
}
function Ready_to_start(tower_rules) {
    console.clear();
    var tab = ["Start Game"];
    var answers = importdata_1.rl.keyInSelect(tab, "Ready to start ?", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        default:
            (0, End_1.End)((0, game_1.default)((0, initialisation_1.default)(tower_rules)));
            break;
        case -1:
            Menu(tower_rules);
            return;
    }
    return;
}
