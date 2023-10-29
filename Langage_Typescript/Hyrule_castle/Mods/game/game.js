"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var Set_up_floor_1 = require("./Set_up_floor");
var action_1 = require("../Actions/action");
var being_of_turn_1 = require("./being_of_turn");
function Game(tower) {
    var keep_playing = true;
    while (tower.nbr_floor > tower.current_floor && keep_playing === true) {
        var fight_list = (0, Set_up_floor_1.Build_fight_list)(tower.floors[tower.current_floor].ennemies);
        var initiative_list = (0, Set_up_floor_1.Set_up_initiative)(fight_list, initialisation_hero_1.hero_list);
        while (fight_list.length > 0 && keep_playing === true) {
            console.clear();
            (0, being_of_turn_1.default)(fight_list, tower);
            keep_playing = (0, action_1.Action)(initiative_list, fight_list, tower);
        }
        tower.current_floor += 1;
    }
    return keep_playing;
}
exports.default = Game;
