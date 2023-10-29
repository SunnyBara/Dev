"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Set_up_rarity_units = void 0;
function Set_up_rarity_units(list) {
    var my_rarity_tab = [];
    var incr = 0;
    var parcours = 0;
    while (incr < 6) {
        parcours = 0;
        var new_rarity_list = {
            rarity: 0,
            list: [],
        };
        var new_string_list = [];
        while (list[parcours] !== undefined) {
            if (list[parcours].rarity === incr) {
                new_string_list.push(list[parcours].name);
            }
            parcours += 1;
        }
        new_rarity_list.list = new_string_list;
        new_rarity_list.rarity = incr;
        my_rarity_tab.push(new_rarity_list);
        incr += 1;
    }
    return my_rarity_tab;
}
exports.Set_up_rarity_units = Set_up_rarity_units;
