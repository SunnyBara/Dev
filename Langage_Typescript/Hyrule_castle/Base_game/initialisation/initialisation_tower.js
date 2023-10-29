"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.combat_log = exports.Initiat_floor = void 0;
var inittower_1 = require("../data/inittower");
var initialisation_ennemie_1 = require("./initialisation_ennemie");
function Testfloor(current_floor, regex) {
    var cr = true;
    if (String(current_floor).match(regex)) {
        cr = false;
    }
    return cr;
}
function Initiat_floor() {
    var incr = 1;
    var tower = inittower_1.Towertemplate;
    while (incr <= tower.nbr_floor) {
        var newfloor = {
            current_floor: 0,
            ennemies: [],
        };
        if (Testfloor(incr, /\d+0/)) {
            (newfloor.current_floor = incr),
                (newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(1, tower.trash_mobs));
        }
        else {
            (newfloor.current_floor = incr),
                (newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(1, tower.boss));
        }
        incr += 1;
        tower.floors.push(newfloor);
    }
    return tower;
}
exports.Initiat_floor = Initiat_floor;
exports.combat_log = [];
