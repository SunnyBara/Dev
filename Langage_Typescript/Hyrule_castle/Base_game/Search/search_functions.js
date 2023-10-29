"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Name_from_list = exports.Search_in_list = exports.Search_in_ennemie_list = exports.Search_in_Hero_list = exports.Search_index_list = void 0;
var importdata_1 = require("../data/importdata");
function Search_index_list(list, unit) {
    var i = 0;
    while (list[i] != unit) {
        i += 1;
    }
    return i;
}
exports.Search_index_list = Search_index_list;
function Search_in_Hero_list(hero_name) {
    return Search_in_list(hero_name, importdata_1.heros_list);
}
exports.Search_in_Hero_list = Search_in_Hero_list;
function Search_in_ennemie_list(ennemie_name) {
    var ennemie = Search_in_list(ennemie_name, importdata_1.trash_mobs_list);
    if (ennemie === undefined) {
        ennemie = Search_in_list(ennemie_name, importdata_1.boss_list);
    }
    return ennemie;
}
exports.Search_in_ennemie_list = Search_in_ennemie_list;
function Search_in_list(ennemie_name, list) {
    var incr = 0;
    while (list[incr] !== undefined && list[incr].name !== ennemie_name) {
        incr += 1;
    }
    return list[incr];
}
exports.Search_in_list = Search_in_list;
function Name_from_list(list) {
    var names = [];
    for (var _i = 0, list_1 = list; _i < list_1.length; _i++) {
        var unit = list_1[_i];
        names.push(unit.name);
    }
    return names;
}
exports.Name_from_list = Name_from_list;
