"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.combat_log = exports.Initiat_floor = void 0;
var inittower_1 = require("../data/inittower");
var random_1 = require("../data/random");
var initialisation_ennemie_1 = require("./initialisation_ennemie");
function Testfloor(current_floor, regex) {
    var cr = true;
    if (String(current_floor).match(regex)) {
        cr = false;
    }
    return cr;
}
function Initiat_floor() {
    var _a, _b;
    var incr = 1;
    var tower = inittower_1.Towertemplate;
    while (incr <= tower.nbr_floor) {
        var newfloor = {
            current_floor: 0,
            ennemies: [],
        };
        if (Testfloor(incr, /\d+0/)) {
            newfloor.current_floor = incr;
            newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)((_a = tower.rules) === null || _a === void 0 ? void 0 : _a.teams, tower.trash_mobs[(0, random_1.Random_rarirty)()]);
        }
        else {
            newfloor.current_floor = incr;
            newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(((_b = tower.rules) === null || _b === void 0 ? void 0 : _b.teams) - 1, tower.trash_mobs[(0, random_1.Random_rarirty)()]);
            newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(1, tower.boss[(0, random_1.Random_rarirty)()]);
        }
        incr += 1;
        tower.floors.push(newfloor);
    }
    return tower;
}
exports.Initiat_floor = Initiat_floor;
exports.combat_log = [];
