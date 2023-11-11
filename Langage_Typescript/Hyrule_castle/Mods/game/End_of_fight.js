"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.level_up = exports.Is_level_up = exports.give_xp = exports.give_loot = exports.End_of_fight = void 0;
var random_1 = require("../data/random");
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
function End_of_fight() {
    give_xp();
    give_loot();
}
exports.End_of_fight = End_of_fight;
function give_loot() {
    var loot = {
        Description: "",
        name: "",
        count: 1
    };
    switch ((0, random_1.Random_rarity)()) {
        case 1:
            loot.name = "Low-level Potion";
            loot.Description = "Restaure 10% of your health and 10 mana";
            break;
        case 2:
            loot.name = "Potion";
            loot.Description = "Restaure 25% of your health and 20 mana";
            break;
        case 3:
            loot.name = "Good Potion";
            loot.Description = "Restaure 35% of your health and 25 mana";
            break;
        case 4:
            loot.name = "High-level Potion";
            loot.Description = "Restaure 50% of your health and 50 mana";
            break;
        case 5:
            loot.name = "Holy Potion";
            loot.Description = "Restaure 100% of your health, 100% mana and give 500xp";
            break;
    }
    initialisation_tower_1.combat_log.push("You loot a ".concat(loot.name));
    initialisation_hero_1.inventory.add(loot);
}
exports.give_loot = give_loot;
function give_xp() {
    initialisation_hero_1.hero_list.forEach(function (hero) {
        if (hero.state.level !== undefined) {
            hero.state.level.exp.current += Math.floor((Math.random() * 38) + 12);
            Is_level_up(hero);
        }
    });
}
exports.give_xp = give_xp;
function Is_level_up(hero) {
    if (hero.state.level !== undefined) {
        if (hero.state.level.exp.current >= hero.state.level.exp.max) {
            level_up(hero);
            initialisation_tower_1.combat_log.push("".concat(hero.name, " \u00E0 level up au niveau ").concat(hero.state.level.current_level));
        }
    }
}
exports.Is_level_up = Is_level_up;
function level_up(hero) {
    hero.characteristics.def += Math.floor(hero.characteristics.def * 0.05);
    hero.characteristics.str += Math.floor(hero.characteristics.str * 0.05);
    hero.characteristics.int += Math.floor(hero.characteristics.int * 0.05);
    hero.characteristics.luck += Math.floor(hero.characteristics.luck * 0.05);
    hero.characteristics.res += Math.floor(hero.characteristics.res * 0.05);
    hero.characteristics.spd += Math.floor(hero.characteristics.spd * 0.05);
    hero.state.health.max += Math.floor(hero.state.health.max * 0.05);
    if (hero.state.mana !== undefined) {
        hero.state.mana.max += Math.floor(hero.state.mana.max * 0.05);
    }
    if (hero.state.level) {
        hero.state.level.current_level += 1;
        hero.state.level.exp.current -= Math.floor(hero.state.level.exp.max);
        hero.state.level.exp.max += Math.floor(hero.state.level.exp.max * 0.2);
    }
}
exports.level_up = level_up;
