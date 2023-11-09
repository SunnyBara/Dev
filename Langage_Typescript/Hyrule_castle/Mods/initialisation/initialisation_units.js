"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Create_unit = exports.Typeunit = void 0;
var search_functions_1 = require("../Search/search_functions");
var importdata_1 = require("../data/importdata");
function Typeunit(name) {
    if ((0, search_functions_1.Search_in_list)(name, importdata_1.trash_mobs_list) !== undefined) {
        return "trash_mobs";
    }
    else if ((0, search_functions_1.Search_in_list)(name, importdata_1.boss_list) !== undefined) {
        return "boss";
    }
    else if ((0, search_functions_1.Search_in_list)(name, importdata_1.heros_list) !== undefined) {
        return "hero";
    }
    else {
        return "problèmes mon reuf";
    }
}
exports.Typeunit = Typeunit;
function Create_unit(unit_Bs) {
    if (unit_Bs.statsmultiplier === undefined) {
        unit_Bs.statsmultiplier = 1;
    }
    var unit_health = {
        current: unit_Bs.hp * unit_Bs.statsmultiplier,
        max: unit_Bs.hp * unit_Bs.statsmultiplier,
    };
    var fightstats = {
        fear: false,
        def_stance: false,
        weakened: false
    };
    var unitstate = {
        health: unit_health,
    };
    if (unit_Bs.mp !== 0) {
        var unit_mana = {
            current: unit_Bs.mp * unit_Bs.statsmultiplier,
            max: unit_Bs.mp * unit_Bs.statsmultiplier,
        };
        unitstate.mana = unit_mana;
    }
    var unit_characteristrics = {
        str: unit_Bs.str * unit_Bs.statsmultiplier,
        int: unit_Bs.int * unit_Bs.statsmultiplier,
        def: unit_Bs.def * unit_Bs.statsmultiplier,
        res: unit_Bs.res * unit_Bs.statsmultiplier,
        spd: unit_Bs.spd * unit_Bs.statsmultiplier,
        luck: unit_Bs.luck * unit_Bs.statsmultiplier,
    };
    var newunit = {
        name: unit_Bs.name,
        type: Typeunit(unit_Bs.name),
        base_stats: unit_Bs,
        state: unitstate,
        characteristics: unit_characteristrics,
        fighting_status: fightstats
    };
    return newunit;
}
exports.Create_unit = Create_unit;
