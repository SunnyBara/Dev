"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Item = exports.Inventory = void 0;
var Inventory = /** @class */ (function () {
    function Inventory() {
        this.monei = 12;
        this.items = [];
    }
    ;
    Inventory.prototype.set_monei = function (change) {
        this.monei += change;
    };
    return Inventory;
}());
exports.Inventory = Inventory;
var Item = /** @class */ (function () {
    function Item() {
    }
    return Item;
}());
exports.Item = Item;
