"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Init_hero = exports.Add_hero = exports.Create_hero = exports.hero_list = void 0;
var search_functions_1 = require("../Search/search_functions");
var importdata_1 = require("../data/importdata");
var random_1 = require("../data/random");
var Initialisation_rarity_1 = require("./Initialisation_rarity");
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
function Init_hero(tower_rules) {
    var hero = [];
    var avaible_hero_list = [1, 2, 3, 4, 5];
    hero.push((0, random_1.Random_hero)(avaible_hero_list));
    if (tower_rules.better_combat_options.team_combat) {
    }
    var set_up_hero_rarity = (0, Initialisation_rarity_1.Set_up_rarity_units)(importdata_1.heros_list);
    while (hero.length > 0) {
        Create_hero(set_up_hero_rarity[hero[0]].list[Math.floor(Math.random() * set_up_hero_rarity[hero[0]].list.length)]);
    }
}
exports.Init_hero = Init_hero;
