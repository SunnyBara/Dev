"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.inventory = exports.Init_hero = exports.Add_hero = exports.Create_hero = exports.hero_list = void 0;
var search_functions_1 = require("../Search/search_functions");
var Set_mods_1 = require("../Start/Set_mods");
var Iventory_1 = require("../data/Iventory");
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
function Init_hero() {
    var hero = [];
    var teamsize = 1;
    if ((0, Set_mods_1.findIfModIsActive)('team_combat')) {
        teamsize = 4;
    }
    var avaible_hero_list = [1, 2, 3, 4, 5];
    while (teamsize > 0) {
        hero.push((0, random_1.Random_hero)(avaible_hero_list));
        teamsize -= 1;
    }
    var set_up_hero_rarity = (0, Initialisation_rarity_1.Set_up_rarity_units)(importdata_1.heros_list);
    for (var _i = 0, hero_1 = hero; _i < hero_1.length; _i++) {
        var rarity = hero_1[_i];
        for (var _a = 0, set_up_hero_rarity_1 = set_up_hero_rarity; _a < set_up_hero_rarity_1.length; _a++) {
            var hero_2 = set_up_hero_rarity_1[_a];
            if (rarity === hero_2.rarity) {
                Add_hero(Create_hero(hero_2.list[0]));
            }
        }
    }
}
exports.Init_hero = Init_hero;
exports.inventory = new Iventory_1.Inventory();
