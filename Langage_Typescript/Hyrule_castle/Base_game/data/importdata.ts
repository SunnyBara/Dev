const fs = require("fs");
var ansi = require("ansi");
export var rl = require("readline-sync");
export var terminal = require('terminal-kit');

const heros_content = fs.readFileSync("./data/heros.json");
const ennemies_content = fs.readFileSync("./data/ennemies.json");
const boss_content = fs.readFileSync("./data/boss.json");
const classes_content = fs.readFileSync("./data/classes.json");
const races_content = fs.readFileSync("./data/races.json");
const spell_content = fs.readFileSync("./data/spell.json");

export const heros_list = JSON.parse(heros_content);
export const trash_mobs_list = JSON.parse(ennemies_content);
export const boss_list = JSON.parse(boss_content);
export const classes_list = JSON.parse(classes_content);
export const races_list = JSON.parse(races_content);
export const spell_list = JSON.parse(spell_content);


