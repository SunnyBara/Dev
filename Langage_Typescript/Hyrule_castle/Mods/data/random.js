"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Random_hero = exports.Random_rarirty = void 0;
function Random_rarirty() {
    var rand = Math.random() * 100;
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
exports.Random_rarirty = Random_rarirty;
function Random_hero(avaible_hero_list) {
    var rarity = Random_rarirty();
    var hero = Choose_hero(rarity, avaible_hero_list);
    return hero;
}
exports.Random_hero = Random_hero;
