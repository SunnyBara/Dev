"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Fireball = exports.Restore = exports.heal = exports.Is_over_heal = exports.Damages_output = void 0;
var display_damages_1 = require("../Display/display_damages");
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
