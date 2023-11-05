"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Initiate_tower = exports.Towertemplate = void 0;
var Tower_1 = require("../data/Tower");
var importdata_1 = require("../data/importdata");
var Initialisation_rarity_1 = require("./Initialisation_rarity");
exports.Towertemplate = new Tower_1.Tower();
function Initiate_tower(tower_rules) {
    exports.Towertemplate.floors = [];
    exports.Towertemplate.nbr_floor = tower_rules.size;
    exports.Towertemplate.current_floor = 0;
    exports.Towertemplate.boss = (0, Initialisation_rarity_1.Set_up_rarity_units)(importdata_1.boss_list);
    exports.Towertemplate.trash_mobs = (0, Initialisation_rarity_1.Set_up_rarity_units)(importdata_1.trash_mobs_list);
    exports.Towertemplate.tower_rules = tower_rules;
}
exports.Initiate_tower = Initiate_tower;
