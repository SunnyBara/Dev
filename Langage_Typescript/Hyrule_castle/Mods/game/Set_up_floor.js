"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.init_innerlist = exports.Set_up_initiative = exports.Build_fight_list = void 0;
var init_tower_template_1 = require("../initialisation/init_tower_template");
var initialisation_ennemie_1 = require("../initialisation/initialisation_ennemie");
function Build_fight_list(ennemie_list) {
    var fight_list = [];
    for (var _i = 0, ennemie_list_1 = ennemie_list; _i < ennemie_list_1.length; _i++) {
        var ennemie = ennemie_list_1[_i];
        fight_list.push((0, initialisation_ennemie_1.Create_ennemie_fighter)(ennemie, init_tower_template_1.Towertemplate.tower_rules));
    }
    return fight_list;
}
exports.Build_fight_list = Build_fight_list;
function Set_up_initiative(hero_list, fight_list) {
    var initiative_list = init_innerlist([hero_list, fight_list]);
    return initiative_list;
}
exports.Set_up_initiative = Set_up_initiative;
function init_innerlist(lists) {
    var init_list = [];
    for (var _i = 0, lists_1 = lists; _i < lists_1.length; _i++) {
        var list = lists_1[_i];
        list.forEach(function (unit) {
            init_list.push(unit);
        });
    }
    init_list.sort(function (a, b) {
        return (b.base_stats.spd - a.base_stats.spd);
    });
    return (init_list);
}
exports.init_innerlist = init_innerlist;
