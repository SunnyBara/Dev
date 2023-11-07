"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var damage_modifiers_1 = require("./Actions/damage_modifiers");
var initialisation_hero_1 = require("./initialisation/initialisation_hero");
var myHero = (0, initialisation_hero_1.Create_hero)('Link');
var my_dummy = (0, initialisation_hero_1.Create_hero)('Link');
my_dummy.name = 'Dummy';
(0, damage_modifiers_1.Attack)(myHero, my_dummy);
