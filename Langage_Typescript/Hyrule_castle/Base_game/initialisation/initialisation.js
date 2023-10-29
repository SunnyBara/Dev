"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var initialisation_hero_1 = require("./initialisation_hero");
var initialisation_tower_1 = require("./initialisation_tower");
function Initialisation() {
    var tower = (0, initialisation_tower_1.Initiat_floor)();
    var firsthero = (0, initialisation_hero_1.Create_hero)("Link");
    (0, initialisation_hero_1.Add_hero)(firsthero);
    return tower;
}
exports.default = Initialisation;
