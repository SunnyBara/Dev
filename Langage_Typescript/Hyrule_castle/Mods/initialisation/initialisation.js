"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var initialisation_tower_1 = require("./initialisation_tower");
function Initialisation(tower_rules) {
    var tower = (0, initialisation_tower_1.Initiat_floor)();
    Init_hero(tower_rules);
    return tower;
}
exports.default = Initialisation;
