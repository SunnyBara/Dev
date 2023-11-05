"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.findIfModIsActive = exports.Find_mod_by_name = exports.Switch_single_mods = exports.Choose_your_mods = exports.Switch_mods = exports.Manage_mod = exports.Mod_manager = void 0;
var importdata_1 = require("../data/importdata");
var init_tower_template_1 = require("../initialisation/init_tower_template");
var start_1 = require("./start");
function Mod_manager(tower_rules) {
    console.clear();
    var tab = ["Combat Option", "Characteristics Options"];
    var answers = importdata_1.rl.keyInSelect(tab, "Choose your Mods\nAll mods are disable by default", {
        cancel: "Back to the menu",
    });
    switch (answers) {
        default:
            Set_up_mods(tower_rules, tab[answers]);
            break;
        case -1:
            (0, start_1.Menu)(tower_rules);
            return;
    }
    return;
}
exports.Mod_manager = Mod_manager;
function Set_up_mods(tower_rules, mod_name) {
    console.clear();
    switch (mod_name.toLowerCase()) {
        case "combat option":
            console.log(tower_rules.better_combat_options.set
                ? "One or more options is currently active"
                : "Combats Options are currently disabled");
            break;
        case "characteristics options":
            console.log(tower_rules.basic_characteristics.set
                ? "One or more options is currently active"
                : "Characteristics options are currently disabled");
            break;
    }
    Manage_mod(tower_rules, mod_name);
}
function Manage_mod(tower_rules, mod_name) {
    var tab = [
        "Disable all ".concat(mod_name),
        "Active all ".concat(mod_name),
        "Choose",
    ];
    var answers = importdata_1.rl.keyInSelect(tab, "What do you want to do ?", {
        cancel: "Back to the Mod manager",
    });
    switch (answers) {
        case 0:
            Switch_mods(mod_name, false, tower_rules);
            Mod_manager(tower_rules);
            break;
        case 1:
            Switch_mods(mod_name, true, tower_rules);
            Mod_manager(tower_rules);
            break;
        case 2:
            Choose_your_mods(mod_name, tower_rules);
            break;
        case -1:
            break;
    }
    return;
}
exports.Manage_mod = Manage_mod;
function Switch_mods(mod_name, change, tower_rules) {
    console.clear();
    switch (mod_name.toLowerCase()) {
        case "characteristics options":
            tower_rules.basic_characteristics.set = change;
            tower_rules.basic_characteristics.Characteristics_mods.forEach(function (mod) {
                mod.set = change;
                return;
            });
            break;
        case "combat option":
            tower_rules.better_combat_options.set = change;
            tower_rules.better_combat_options.Combat_mods.forEach(function (mod) {
                mod.set = change;
                return;
            });
            break;
    }
    return;
}
exports.Switch_mods = Switch_mods;
function Choose_your_mods(mod_name, tower_rules) {
    var stop = true;
    console.clear();
    var _loop_1 = function () {
        switch (mod_name.toLowerCase()) {
            case "characteristics options":
                var Chara_tab_1 = [];
                tower_rules.basic_characteristics.Characteristics_mods.forEach(function (mods) { Chara_tab_1.push(mods.mod_name); });
                var Char_mods = importdata_1.rl.keyInSelect(Chara_tab_1, "What do you want to do ?", { cancel: "Back to the Mod manager", });
                switch (Char_mods) {
                    default:
                        Switch_single_mods(Find_mod_by_name(tower_rules, Chara_tab_1[Char_mods]));
                        break;
                    case -1:
                        stop = false;
                        Mod_manager(tower_rules);
                        return { value: void 0 };
                }
                break;
            case "combat option":
                var Combat_tab_1 = [];
                tower_rules.better_combat_options.Combat_mods.forEach(function (mods) { Combat_tab_1.push(mods.mod_name); });
                var Combat_mods = importdata_1.rl.keyInSelect(Combat_tab_1, "What do you want to do ?", { cancel: "Back to the Mod manager", });
                switch (Combat_mods) {
                    default:
                        Switch_single_mods(Find_mod_by_name(tower_rules, Combat_tab_1[Combat_mods]));
                        break;
                    case -1:
                        stop = false;
                        console.clear();
                        Mod_manager(tower_rules);
                        return { value: void 0 };
                }
                break;
        }
    };
    while (stop) {
        var state_1 = _loop_1();
        if (typeof state_1 === "object")
            return state_1.value;
    }
    return;
}
exports.Choose_your_mods = Choose_your_mods;
function Switch_single_mods(mod) {
    if (mod !== null) {
        console.clear();
        mod.set = !mod.set;
        console.log("".concat(mod.mod_name), mod.set
            ? "is active"
            : "is disable");
    }
    return;
}
exports.Switch_single_mods = Switch_single_mods;
function Find_mod_by_name(tower_rules, mod_name) {
    var mod_found = null;
    var find = tower_rules.basic_characteristics.Characteristics_mods.every(function (mod) {
        if (mod.mod_name === mod_name) {
            mod_found = mod;
            return false;
        }
        return true;
    });
    if (find) {
        tower_rules.better_combat_options.Combat_mods.every(function (mod) {
            if (mod.mod_name === mod_name) {
                mod_found = mod;
                return false;
            }
            return true;
        });
    }
    return (mod_found);
}
exports.Find_mod_by_name = Find_mod_by_name;
function findIfModIsActive(mod_name) {
    for (var _i = 0, _a = init_tower_template_1.Towertemplate.tower_rules.better_combat_options.Combat_mods; _i < _a.length; _i++) {
        var mod = _a[_i];
        if (mod.mod_name === mod_name) {
            return (mod.set);
        }
    }
    for (var _b = 0, _c = init_tower_template_1.Towertemplate.tower_rules.basic_characteristics.Characteristics_mods; _b < _c.length; _b++) {
        var mod = _c[_b];
        if (mod.mod_name === mod_name) {
            return (mod.set);
        }
    }
}
exports.findIfModIsActive = findIfModIsActive;
