"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Initiate_tower = exports.Towertemplate = void 0;
var Randoms_1 = require("../initialisation/Randoms");
var importdata_1 = require("./importdata");
exports.Towertemplate = {
    nbr_floor: 10,
    current_floor: 0,
    trash_mobs: [],
    boss: [],
    floors: [],
};
function Initiate_tower(tower_rules) {
    exports.Towertemplate.nbr_floor = tower_rules.size;
    exports.Towertemplate.boss = (0, Randoms_1.Set_up_rarity_units)(importdata_1.boss_list);
    exports.Towertemplate.trash_mobs = (0, Randoms_1.Set_up_rarity_units)(importdata_1.trash_mobs_list);
}
exports.Initiate_tower = Initiate_tower;
