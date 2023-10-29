"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Is_it_dead = void 0;
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var search_functions_1 = require("../Search/search_functions");
function Is_it_dead(target_list, unit) {
    if (unit.state.health.current <= 0) {
        initialisation_tower_1.combat_log.push("".concat(unit.name, " is dead !"));
        Is_Dead(target_list, unit);
    }
    return unit;
}
exports.Is_it_dead = Is_it_dead;
function Is_Dead(target_list, unit) {
    target_list.splice((0, search_functions_1.Search_index_list)(target_list, unit), 1);
}
