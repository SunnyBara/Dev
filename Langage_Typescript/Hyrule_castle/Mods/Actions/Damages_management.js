"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.heal = exports.Is_over_heal = exports.Damages_output = void 0;
var display_damages_1 = require("../Display/display_damages");
var initialisation_damages_1 = require("../initialisation/initialisation_damages");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var Death_management_1 = require("./Death_management");
function Damages_output(unit, target, damages, target_list) {
    var saveold_hp = unit.state.health.current;
    target.state.health.current -= damages.damages;
    Is_over_heal(target);
    if (damages.damages < 0) {
        damages.damages = saveold_hp - target.state.health.current;
    }
    (0, display_damages_1.Add_Damages_combat_log)(target, unit, damages, initialisation_tower_1.combat_log);
    (0, Death_management_1.Is_it_dead)(target_list, target);
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
// export function spell_damage(unit: Units, target: Units, spell_name: string) {
//     let damage: number  =
// }
function heal(target, target_list) {
    var heal = (0, initialisation_damages_1.default)();
    heal.damages = Math.floor(-target.state.health.max / 2);
    return heal;
}
exports.heal = heal;
