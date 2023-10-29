"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var display_1 = require("../Display/display");
var display_damages_1 = require("../Display/display_damages");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
function Begin_of_turn(fight_list, tower) {
    (0, display_1.Display)(fight_list, tower.current_floor);
    (0, display_damages_1.Reset_combat_log)(initialisation_tower_1.combat_log);
    return;
}
exports.default = Begin_of_turn;
