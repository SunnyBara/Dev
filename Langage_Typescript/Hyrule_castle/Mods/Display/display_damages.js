"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Reset_combat_log = exports.Display_Combat_log = exports.Add_Damages_combat_log = void 0;
function Add_Damages_combat_log(target, unit, damage, combat_log) {
    if (damage.Crushing) {
        combat_log.push("Crushing hit !");
    }
    else if (damage.Glancing) {
        combat_log.push("Glancing hit ...");
    }
    if (damage.damages > 0)
        combat_log.push(damage.Crit
            ? "".concat(unit.name, " CRITS ").concat(target.name, " FOR  ").concat(Math.floor(damage.damages), " DAMAGES ! ")
            : "".concat(unit.name, " deals ").concat(Math.floor(damage.damages), " to ").concat(target.name));
    else {
        if (target === unit) {
            combat_log.push(damage.Crit
                ? "".concat(unit.name, " HEALS CRIT HIMSELF FOR ").concat(-Math.floor(damage.damages), " !")
                : "".concat(unit.name, " heals himself ").concat(-Math.floor(damage.damages), "Hp"));
        }
        else {
            combat_log.push(damage.Crit
                ? "".concat(unit.name, " HEALS CRIT ").concat(target.name, " FOR  ").concat(-Math.floor(damage.damages), " !")
                : "".concat(unit.name, " heals ").concat(target.name, "  ").concat(-Math.floor(damage.damages), "Hp"));
        }
    }
    return;
}
exports.Add_Damages_combat_log = Add_Damages_combat_log;
function Display_Combat_log(combat_log) {
    console.log("previous turn logs \n");
    for (var _i = 0, combat_log_1 = combat_log; _i < combat_log_1.length; _i++) {
        var log = combat_log_1[_i];
        console.log(log);
    }
    return;
}
exports.Display_Combat_log = Display_Combat_log;
function Reset_combat_log(combat_log) {
    while (combat_log.length > 0) {
        combat_log.pop();
    }
}
exports.Reset_combat_log = Reset_combat_log;
