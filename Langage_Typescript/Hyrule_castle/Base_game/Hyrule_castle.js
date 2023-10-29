"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Hyrule_castle = void 0;
var End_1 = require("./End/End");
var game_1 = require("./game/game");
var initialisation_1 = require("./initialisation/initialisation");
function Hyrule_castle() {
    (0, End_1.End)((0, game_1.default)((0, initialisation_1.default)()));
}
exports.Hyrule_castle = Hyrule_castle;
