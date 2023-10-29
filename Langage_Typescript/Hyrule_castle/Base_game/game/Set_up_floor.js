"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Set_up_initiative = exports.Build_fight_list = void 0;
var initialisation_ennemie_1 = require("../initialisation/initialisation_ennemie");
function Build_fight_list(ennemie_list) {
    var fight_list = [];
    for (var _i = 0, ennemie_list_1 = ennemie_list; _i < ennemie_list_1.length; _i++) {
        var ennemie = ennemie_list_1[_i];
        fight_list.push((0, initialisation_ennemie_1.Create_ennemie_fighter)(ennemie));
    }
    return fight_list;
}
exports.Build_fight_list = Build_fight_list;
function Set_up_initiative(hero_list, fight_list) {
    var initiative_list = [hero_list[0], fight_list[0]];
    return initiative_list;
}
exports.Set_up_initiative = Set_up_initiative;
