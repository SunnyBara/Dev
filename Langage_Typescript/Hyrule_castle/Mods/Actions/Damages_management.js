"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.item_effect = exports.Fireball = exports.Restore = exports.heal = exports.Is_over_heal = exports.Damages_output = void 0;
var display_damages_1 = require("../Display/display_damages");
var End_of_fight_1 = require("../game/End_of_fight");
var initialisation_damages_1 = require("../initialisation/initialisation_damages");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var Damage_modifiers_1 = require("./Damage_modifiers");
function Damages_output(unit, target, damages, target_list) {
    var saveold_hp = unit.state.health.current;
    target.state.health.current -= Math.floor(damages.damages);
    Is_over_heal(target);
    if (damages.damages < 0) {
        damages.damages = saveold_hp - target.state.health.current;
    }
    (0, display_damages_1.Add_Damages_combat_log)(target, unit, damages, initialisation_tower_1.combat_log);
    return damages;
}
exports.Damages_output = Damages_output;
function Is_over_heal(unit) {
    if (unit.state.health.current > unit.state.health.max) {
        unit.state.health.current = unit.state.health.max;
    }
    return unit;
}
exports.Is_over_heal = Is_over_heal;
function heal(target) {
    var heal = (0, initialisation_damages_1.default)();
    heal.damages = -100;
    return heal;
}
exports.heal = heal;
function Restore(unit, target) {
    if (target.state.mana != undefined) {
        var saveold_mp = target.state.mana.current;
        target.state.mana.current += 100;
        Is_over_mana(target);
        var restored = saveold_mp - target.state.mana.current;
        initialisation_tower_1.combat_log.push("".concat(unit.name, " Restore ").concat(-restored, " mana to ").concat(target.name));
    }
}
exports.Restore = Restore;
function Is_over_mana(unit) {
    if (unit.state.mana != undefined) {
        if (unit.state.mana.current > unit.state.mana.max) {
            unit.state.mana.current = unit.state.mana.max;
            return unit;
        }
    }
}
function Fireball(unit, target) {
    var damages = (0, initialisation_damages_1.default)();
    damages.damages = 200;
    damages.damages = (0, Damage_modifiers_1.Damage_modif)(unit, target, damages, "magic");
    damages.damages = Math.floor(damages.damages * 1);
    return damages;
}
exports.Fireball = Fireball;
function item_effect(item, target) {
    var heal = 0;
    var mana = 0;
    var exp = 0;
    switch (item.name) {
        case "Low-level Potion":
            heal = Math.floor(target.state.health.max * 0.1);
            mana = 10;
            exp = 0;
            break;
        case "Potion":
            heal = Math.floor(target.state.health.max * 0.25);
            mana = 20;
            exp = 0;
            break;
        case "Good Potion":
            heal = Math.floor(target.state.health.max * 0.35);
            mana = 25;
            exp = 0;
            break;
        case "High-level Potion":
            heal = Math.floor(target.state.health.max * 0.5);
            mana = 50;
            exp = 0;
            break;
        case "Holy Potion":
            heal = Math.floor(target.state.health.max);
            if (target.state.mana)
                mana = target.state.mana.max;
            exp = 500;
            break;
    }
    target.state.health.current += heal;
    Is_over_heal(target);
    if (target.state.mana) {
        target.state.mana.current += mana;
        Is_over_mana(target);
    }
    if (target.state.level) {
        target.state.level.exp.current += exp;
        while (target.state.level.exp.current >= target.state.level.exp.max) {
            (0, End_of_fight_1.Is_level_up)(target);
        }
    }
    return;
}
exports.item_effect = item_effect;
