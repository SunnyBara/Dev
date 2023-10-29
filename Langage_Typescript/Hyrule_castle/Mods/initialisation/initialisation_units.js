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
    var unit_health = {
        current: unit_Bs.hp,
        max: unit_Bs.hp,
    };
    var unitstate = {
        health: unit_health,
    };
    if (unit_Bs.mp !== 0) {
        var unit_mana = {
            current: unit_Bs.mp,
            max: unit_Bs.mp,
        };
        unitstate.mana = unit_mana;
    }
    var unit_characteristrics = {
        str: unit_Bs.str,
        int: unit_Bs.int,
        def: unit_Bs.def,
        res: unit_Bs.res,
        spd: unit_Bs.spd,
        luck: unit_Bs.luck,
    };
    var newunit = {
        name: unit_Bs.name,
        type: Typeunit(unit_Bs.name),
        base_stats: unit_Bs,
        state: unitstate,
        characteristics: unit_characteristrics,
    };
    return newunit;
}
exports.Create_unit = Create_unit;
