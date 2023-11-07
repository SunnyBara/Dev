"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Attack = exports.Damage_modif = void 0;
var search_functions_1 = require("../Search/search_functions");
var initialisation_damages_1 = require("../initialisation/initialisation_damages");
function Damage_modif(unit, target, damage, type) {
    damage.damages = Is_crit(damage, unit);
    damage.damages = Is_magic_or_physical(target, damage, type);
    damage.damages = Is_advantage_or_weak(target, damage, unit);
    damage.damages = Is_it_fear(unit, damage);
    damage.damages = Is_it_weak(target, damage);
    damage.damages = Is_it_on_def(target, damage);
    return damage.damages;
}
exports.Damage_modif = Damage_modif;
function Is_crit(damage, unit) {
    if (unit.characteristics.luck + 5 >= Math.floor(Math.random() * 100)) {
        console.log(" critique");
        damage.damages *= 2;
        damage.Crit = true;
    }
    return damage.damages;
}
function Is_magic_or_physical(target, damage, type) {
    if (type === "magic") {
        damage.damages =
            damage.damages - (damage.damages * target.characteristics.res) / 100;
    }
    else {
        damage.damages =
            damage.damages - (damage.damages * target.characteristics.def) / 100;
    }
    console.log(damage.damages);
    return damage.damages;
}
function Is_it_fear(unit, damage) {
    if (unit.fighting_status.fear === true) {
        damage.damages = damage.damages / 2;
    }
    return damage.damages;
}
function Is_it_weak(unit, damage) {
    if (unit.fighting_status.weakened === true) {
        damage.damages = damage.damages * 1.5;
        damage.Crushing = true;
    }
    return damage.damages;
}
function Is_it_on_def(unit, damage) {
    if (unit.fighting_status.def_stance === true) {
        damage.damages = damage.damages / 2;
        damage.Glancing = true;
    }
    return damage.damages;
}
function Is_advantage_or_weak(target, damage, unit) {
    var classes_unit = (0, search_functions_1.Search_class)(unit.base_stats.class);
    if ((0, search_functions_1.Search_race_advantage)(classes_unit.strengths, target.base_stats.class)) {
        damage.damages += damage.damages;
        damage.Crushing = true;
    }
    if ((0, search_functions_1.Search_race_advantage)(classes_unit.weaknesses, target.base_stats.class)) {
        damage.damages = damage.damages / 2;
        damage.Glancing = true;
    }
    if ((0, search_functions_1.Search_class_advantage)(classes_unit.strengths, target.base_stats.class)) {
        damage.damages += damage.damages;
        damage.Crushing = true;
    }
    if ((0, search_functions_1.Search_class_advantage)(classes_unit.weaknesses, target.base_stats.class)) {
        damage.damages = damage.damages / 2;
        damage.Glancing = true;
    }
    return damage.damages;
}
function Attack(unit, target) {
    var damages = (0, initialisation_damages_1.default)();
    damages.damages = unit.characteristics.str;
    damages.damages = Damage_modif(unit, target, damages, "physical");
    return damages;
}
exports.Attack = Attack;
