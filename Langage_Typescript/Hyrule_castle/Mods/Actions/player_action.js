"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.PlayerAction = void 0;
var Damages_management_1 = require("./Damages_management");
var search_functions_1 = require("../Search/search_functions");
var display_1 = require("../game/display");
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var importdata_1 = require("../data/importdata");
function PlayerAction(unit, fight_list, tower) {
    var tab = ["Fight", "Run away"];
    var answers = importdata_1.rl.keyInSelect(tab, "It's ".concat(unit.name, " 's turns"), {
        cancel: "Leave tower",
    });
    switch (answers) {
        case 0:
            Letsfight(unit, fight_list, tower);
            break;
        case 1:
            console.log("fonction de fuite");
            break;
        case -1:
            return false;
    }
    return true;
}
exports.PlayerAction = PlayerAction;
function Letsfight(unit, fight_list, tower) {
    var fight_tab = ["Attack", "Heal"];
    console.clear();
    (0, display_1.Display)(fight_list, tower.current_floor + 1);
    var answers = importdata_1.rl.keyInSelect(fight_tab, "Choose your action", {
        cancel: "Back to previous options",
    });
    switch (answers) {
        case 0:
            var target_to_attack = Choosetarget(unit, fight_list, fight_list, tower);
            if (target_to_attack !== undefined) {
                (0, Damages_management_1.Damages_output)(unit, target_to_attack, (0, Damages_management_1.Attack)(unit), fight_list);
            }
            break;
        case 1:
            var target_to_heal = Choosetarget(unit, fight_list, initialisation_hero_1.hero_list, tower);
            if (target_to_heal != undefined) {
                (0, Damages_management_1.Damages_output)(unit, target_to_heal, (0, Damages_management_1.heal)(target_to_heal, initialisation_hero_1.hero_list), initialisation_hero_1.hero_list);
            }
            break;
        case -1:
            PlayerAction(unit, fight_list, tower);
            break;
    }
}
function Choosetarget(unit, fight_list, target_list, tower) {
    console.clear();
    (0, display_1.Display)(fight_list, tower.current_floor + 1);
    var target_name_list = (0, search_functions_1.Name_from_list)(target_list);
    var answers = importdata_1.rl.keyInSelect(target_name_list, "Choose your target", {
        cancel: "Choose another attack",
    });
    switch (answers) {
        case -1:
            Letsfight(unit, fight_list, tower);
            return undefined;
        default:
            if (answers !== undefined) {
                return (0, search_functions_1.Search_in_list)(target_name_list[answers], target_list);
            }
    }
    return undefined;
}
