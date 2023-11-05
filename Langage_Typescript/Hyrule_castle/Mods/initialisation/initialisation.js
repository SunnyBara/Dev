"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var init_tower_template_1 = require("./init_tower_template");
var initialisation_hero_1 = require("./initialisation_hero");
var initialisation_tower_1 = require("./initialisation_tower");
function Initialisation(tower_rules) {
    (0, init_tower_template_1.Initiate_tower)(tower_rules);
    var tower = (0, initialisation_tower_1.Initiat_floor)();
    (0, initialisation_hero_1.Init_hero)();
    return tower;
}
exports.default = Initialisation;
