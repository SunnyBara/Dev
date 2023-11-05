"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.combat_log = exports.Initiat_floor = exports.Testfloor = void 0;
var Set_mods_1 = require("../Start/Set_mods");
var random_1 = require("../data/random");
var init_tower_template_1 = require("./init_tower_template");
var initialisation_ennemie_1 = require("./initialisation_ennemie");
function Testfloor(current_floor, regex) {
    var cr = true;
    if (String(current_floor).match(regex)) {
        cr = false;
    }
    return cr;
}
exports.Testfloor = Testfloor;
function Initiat_floor() {
    var incr = 1;
    var teamsize = 1;
    if ((0, Set_mods_1.findIfModIsActive)('team_combat')) {
        teamsize = 4;
    }
    while (incr <= init_tower_template_1.Towertemplate.nbr_floor) {
        var newfloor = {
            current_floor: 0,
            ennemies: [],
        };
        if (Testfloor(incr, /\d+0/)) {
            newfloor.current_floor = incr;
            newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(teamsize, init_tower_template_1.Towertemplate.trash_mobs[(0, random_1.Random_rarity)()]);
        }
        else {
            var random_boss = (0, random_1.Random_rarity)();
            while (init_tower_template_1.Towertemplate.boss[random_boss].list.length === 0) {
                random_boss = (((random_boss + 1) % 5) + 1);
            }
            var boss_name = (0, initialisation_ennemie_1.Init_ennemie_list)(1, init_tower_template_1.Towertemplate.boss[random_boss]);
            init_tower_template_1.Towertemplate.boss[random_boss].list.splice(init_tower_template_1.Towertemplate.boss[random_boss].list.indexOf(boss_name[0]), 1);
            newfloor.current_floor = incr;
            newfloor.ennemies = (0, initialisation_ennemie_1.Init_ennemie_list)(teamsize - 1, init_tower_template_1.Towertemplate.trash_mobs[(0, random_1.Random_rarity)()]);
            newfloor.ennemies.push(boss_name[0]);
        }
        incr += 1;
        init_tower_template_1.Towertemplate.floors.push(newfloor);
    }
    return init_tower_template_1.Towertemplate;
}
exports.Initiat_floor = Initiat_floor;
exports.combat_log = [];
