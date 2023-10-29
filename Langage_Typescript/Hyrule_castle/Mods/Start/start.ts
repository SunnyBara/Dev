import { rl } from "../data/importdata";
import Initialisation from "../initialisation/initialisation";
import { Mod_manager } from "./Set_mods";
import { Initiate_tower_rules, Tower_rules } from "./tower_rules";
import Game from '../game/game';
import {End} from '../End/End'


export  function Start() {
	let tower_rules: Tower_rules = Initiate_tower_rules();
	Menu(tower_rules);
	return;
}

export  function Menu(tower_rules : Tower_rules) {
	console.clear()
	const tab: string[] = ["New game", "Optionnal Mods"];
	const answers = rl.keyInSelect(tab, `Welcome !`, {
		cancel: "Quit",
	});
	switch (answers) {
		case 0:
			Set_up_game_rules(tower_rules);
			break;
		case 0:
			Mod_manager(tower_rules);
			break;

		case -1:
			return;
	}
	return;
}

function Set_up_game_rules(tower_rules: Tower_rules) {
	console.clear();
	const tab: string[] = ["Normal", "Difficult", "Insane"];
	const answers = rl.keyInSelect(tab, `Choose your difficultie`, {
		cancel: "Back to the menu",
	});
	switch (answers) {
		default:
			tower_rules.difficultie = tab[answers];
			break;
		case -1:
			Menu(tower_rules)
	}
	Choose_size_of_tower(tower_rules);
	return;
}
function Choose_size_of_tower(tower_rules: Tower_rules) {
	console.clear()
	const tab: string[] = ["10", "20", "50", "100"];
	const answers = rl.keyInSelect(tab, `Choose your difficultie`, {
		cancel: "Back to the menu",
	});
	switch (answers) {
		default:
			tower_rules.size = parseInt(tab[answers]);
			break;
		case -1:
			Set_up_game_rules(tower_rules);
			return;
	}
	console.log(tower_rules);
	Ready_to_start(tower_rules);
	return;
}
function Ready_to_start(tower_rules: Tower_rules) {
	console.clear()
	const tab: string[] = ["Start Game", "Change Mods"];
	const answers = rl.keyInSelect(tab, `Ready to start ?`, {
		cancel: "Back to the menu",
	});
	switch (answers) {
		default:
			End(Game(Initialisation(tower_rules)));
			break;
		case -1:
			Menu(tower_rules);
			return;
	}
	console.log(tower_rules);

	return;
}
