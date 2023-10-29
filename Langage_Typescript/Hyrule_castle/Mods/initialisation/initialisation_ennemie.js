"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Add_fighter = exports.Create_ennemie_fighter = exports.Init_ennemie_list = void 0;
var search_functions_1 = require("../Search/search_functions");
var initialisation_units_1 = require("./initialisation_units");
function Init_ennemie_list(nbr_ennemie, ennemies) {
    var ennemie_at_this_floor = [];
    var incr = 0;
    while (incr < nbr_ennemie) {
        ennemie_at_this_floor.push(ennemies.list[Math.floor(Math.random() * ennemies.list.length)]);
        incr += 1;
    }
    return ennemie_at_this_floor;
}
exports.Init_ennemie_list = Init_ennemie_list;
function Create_ennemie_fighter(ennemie_name) {
    var ennemiestats = (0, search_functions_1.Search_in_ennemie_list)(ennemie_name);
    var newennemie = (0, initialisation_units_1.Create_unit)(ennemiestats);
    return newennemie;
}
exports.Create_ennemie_fighter = Create_ennemie_fighter;
function Add_fighter(ennemie, fight_list) {
    fight_list.push(ennemie);
    return;
}
exports.Add_fighter = Add_fighter;
