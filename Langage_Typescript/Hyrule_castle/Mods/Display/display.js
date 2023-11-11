"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Display = exports.Display_Floor = void 0;
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var display_damages_1 = require("./display_damages");
function Calcul_health_bar(percentage_health) {
    var HealthBar = "/";
    var incr = 0;
    while (incr < percentage_health) {
        if (incr % 10 === 0) {
            HealthBar += "/";
        }
        else {
            HealthBar += " ";
        }
        incr += 1;
    }
    return HealthBar;
}
function Displayfighters(fight_list, hero_list) {
    for (var _i = 0, fight_list_1 = fight_list; _i < fight_list_1.length; _i++) {
        var ennemie = fight_list_1[_i];
        var HealthBar = Calcul_health_bar(Math.floor((ennemie.state.health.current / ennemie.state.health.max) * 100));
        console.log("\u001B[37;46;40m".concat(ennemie.name));
        console.log("\u001b[30;46;41m" + HealthBar + "\u001b[37;46;40m");
        console.log("Hp : ".concat(ennemie.state.health.current, "/").concat(ennemie.state.health.max), ennemie.state.mana
            ? "\nMana : ".concat(ennemie.state.mana.current, "/").concat(ennemie.state.mana.max)
            : "");
    }
    for (var _a = 0, hero_list_1 = hero_list; _a < hero_list_1.length; _a++) {
        var hero = hero_list_1[_a];
        var HealthBar = Calcul_health_bar(Math.floor((hero.state.health.current / hero.state.health.max) * 100));
        console.log("".concat(hero.name), hero.state.level ? " lv ".concat(hero.state.level.current_level) : "");
        console.log("\u001b[37;46;42m" + HealthBar + "\u001b[37;46;40m");
        console.log("Hp : ".concat(hero.state.health.current, "/").concat(hero.state.health.max), hero.state.mana
            ? "\nMana : ".concat(hero.state.mana.current, "/").concat(hero.state.mana.max)
            : "", hero.state.level
            ? "\nExp : ".concat(hero.state.level.exp.current, "/").concat(hero.state.level.exp.max)
            : "");
    }
}
exports.default = Displayfighters;
function Display_Floor(current_floor) {
    console.log("CURRENT FLOOR ".concat(current_floor, "\n"));
    return;
}
exports.Display_Floor = Display_Floor;
function Display(fight_list, current_floor) {
    Display_Floor(current_floor);
    Displayfighters(fight_list, initialisation_hero_1.hero_list);
    console.log("\n");
    if (initialisation_tower_1.combat_log.length > 0) {
        (0, display_damages_1.Display_Combat_log)(initialisation_tower_1.combat_log);
    }
}
exports.Display = Display;
