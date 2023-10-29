"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Add_hero = exports.Create_hero = exports.hero_list = void 0;
var search_functions_1 = require("../Search/search_functions");
var initialisation_units_1 = require("./initialisation_units");
exports.hero_list = [];
function Create_hero(hero_name) {
    var herostats = (0, search_functions_1.Search_in_Hero_list)(hero_name);
    var newhero = (0, initialisation_units_1.Create_unit)(herostats);
    return newhero;
}
exports.Create_hero = Create_hero;
function Add_hero(hero) {
    exports.hero_list.push(hero);
    return;
}
exports.Add_hero = Add_hero;
