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
    Inventory.prototype.add = function (item) {
        if (this.exist(item)) {
            var my_item = this.find_item(item.name);
            if (my_item !== null)
                my_item.count += 1;
        }
        else {
            this.items.push(item);
        }
    };
    Inventory.prototype.Use = function (item) {
        var my_item = this.find_item(item.name);
        if (my_item !== null) {
            my_item.count -= 1;
            if (my_item.count === 0) {
                this.items.splice(this.items.indexOf(my_item), 1);
            }
        }
    };
    Inventory.prototype.exist = function (item) {
        for (var _i = 0, _a = this.items; _i < _a.length; _i++) {
            var items = _a[_i];
            if (item.name === items.name) {
                return (true);
            }
        }
        return (false);
    };
    Inventory.prototype.find_item = function (item_name) {
        for (var _i = 0, _a = this.items; _i < _a.length; _i++) {
            var items = _a[_i];
            if (item_name === items.name) {
                return (items);
            }
        }
        return (null);
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
