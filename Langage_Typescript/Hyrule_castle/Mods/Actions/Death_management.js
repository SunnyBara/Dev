"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Kill_unit = void 0;
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var search_functions_1 = require("../Search/search_functions");
function Is_Dead(target_list, unit) {
    target_list.splice((0, search_functions_1.Search_index_list)(target_list, unit), 1);
}
function Kill_unit(target_list) {
    var incr = 0;
    while (incr < target_list.length) {
        if (target_list[incr].state.health.current <= 0) {
            initialisation_tower_1.combat_log.push("".concat(target_list[incr].name, " is dead !"));
            Is_Dead(target_list, target_list[incr]);
            incr = -1;
        }
        incr += 1;
    }
    return;
}
exports.Kill_unit = Kill_unit;
