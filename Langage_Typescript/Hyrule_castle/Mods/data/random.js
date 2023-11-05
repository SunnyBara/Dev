"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Choose_hero = exports.Random_hero = exports.Random_rarity = void 0;
function Random_rarity() {
    var rand = Math.floor(Math.random() * 100);
    if (rand < 50) {
        return 1;
    }
    else if (rand < 80) {
        return 2;
    }
    else if (rand < 95) {
        return 3;
    }
    else if (rand < 99) {
        return 4;
    }
    else {
        return 5;
    }
}
exports.Random_rarity = Random_rarity;
function Random_hero(avaible_hero_list) {
    var rarity = Random_rarity();
    var hero = Choose_hero(rarity, avaible_hero_list);
    return hero;
}
exports.Random_hero = Random_hero;
function Choose_hero(rarity, avaible_hero_list) {
    avaible_hero_list.sort(function (a, b) { return b - a; });
    if (avaible_hero_list.length !== 0) {
        var found = avaible_hero_list.find(function (hero_rarity) {
            return (hero_rarity <= rarity);
        });
        while (found === undefined) {
            rarity += 1;
            found = avaible_hero_list.find(function (hero_rarity) {
                return (hero_rarity <= rarity);
            });
        }
        if (found === undefined) {
            found = 0;
        }
        avaible_hero_list.splice(avaible_hero_list.indexOf(found), 1);
        return (found);
    }
    else {
        return (0);
    }
}
exports.Choose_hero = Choose_hero;
