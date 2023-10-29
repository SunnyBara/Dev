"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Action = void 0;
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var Mob_action_1 = require("./Mob_action");
var player_action_1 = require("./player_action");
var Check_fighters_1 = require("./Check_fighters");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
function Action(initiative, fight_list, tower) {
    for (var _i = 0, initiative_1 = initiative; _i < initiative_1.length; _i++) {
        var unit = initiative_1[_i];
        if (unit.type === "trash_mobs" || unit.type === "boss") {
            var recap = (0, Mob_action_1.Mobaction)(unit, initialisation_hero_1.hero_list);
            if ((0, Check_fighters_1.Checkteamalive)(initialisation_hero_1.hero_list)) {
                return false;
            }
        }
        else if (unit.type == "hero") {
            if (!(0, player_action_1.PlayerAction)(unit, fight_list, tower)) {
                return false;
            }
            if ((0, Check_fighters_1.Checkteamalive)(fight_list)) {
                initialisation_tower_1.combat_log.push("Ennemies has been defeated");
            }
        }
    }
    return true;
}
exports.Action = Action;
