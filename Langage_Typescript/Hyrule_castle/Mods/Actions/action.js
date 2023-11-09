"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Action = void 0;
var initialisation_hero_1 = require("../initialisation/initialisation_hero");
var Mob_action_1 = require("./Mob_action");
var player_action_1 = require("./player_action");
var Check_fighters_1 = require("./Check_fighters");
var initialisation_tower_1 = require("../initialisation/initialisation_tower");
var display_damages_1 = require("../Display/display_damages");
var End_of_fight_1 = require("./End_of_fight");
var Death_management_1 = require("./Death_management");
function Action(initiative, fight_list, tower) {
    for (var _i = 0, initiative_1 = initiative; _i < initiative_1.length; _i++) {
        var unit = initiative_1[_i];
        if (unit.type === "trash_mobs" || unit.type === "boss") {
            var recap = (0, Mob_action_1.Mobaction)(unit, initialisation_hero_1.hero_list);
            (0, Death_management_1.Kill_unit)(initialisation_hero_1.hero_list);
            if ((0, Check_fighters_1.Checkteamalive)(initialisation_hero_1.hero_list)) {
                return false;
            }
        }
        else if (unit.type == "hero") {
            if (!(0, player_action_1.PlayerAction)(unit, fight_list, tower)) {
                return false;
            }
            (0, Death_management_1.Kill_unit)(fight_list);
            if ((0, Check_fighters_1.Checkteamalive)(fight_list)) {
                (0, display_damages_1.Reset_combat_log)(initialisation_tower_1.combat_log);
                initialisation_tower_1.combat_log.push("Ennemies has been defeated");
                (0, End_of_fight_1.End_of_fight)();
                return true;
            }
        }
    }
    return true;
}
exports.Action = Action;
