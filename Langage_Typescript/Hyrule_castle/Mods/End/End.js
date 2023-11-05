"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.End = void 0;
var Ascii_Art_1 = require("../Display/Ascii_Art");
var Hyrule_castle_1 = require("../Hyrule_castle");
var importdata_1 = require("../data/importdata");
function End(keep_playing) {
    console.clear();
    (0, Ascii_Art_1.Display_gameover)();
    if (keep_playing === true) {
        console.log("CONGRATULATION YOU WON");
    }
    else if (keep_playing === false) {
        (0, Ascii_Art_1.Display_gameover)();
    }
    if (importdata_1.rl.keyInYN("Do you want another game ?\n")) {
        (0, Hyrule_castle_1.default)();
    }
    else {
        console.log("Okay , Good Bye !");
    }
    return;
}
exports.End = End;
