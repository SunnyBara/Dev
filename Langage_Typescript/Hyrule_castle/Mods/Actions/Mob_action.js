"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Mobaction = void 0;
var Damages_management_1 = require("./Damages_management");
var damage_modifiers_1 = require("./damage_modifiers");
function Mobaction(unit, hero_list) {
    var target = hero_list[Math.floor(Math.random() * hero_list.length)];
    (0, Damages_management_1.Damages_output)(unit, target, (0, damage_modifiers_1.Attack)(unit, target), hero_list);
    return;
}
exports.Mobaction = Mobaction;
