import { Damages_output, Fireball } from "./Actions/Damages_management";
import { End } from "./End/End";
import { Mod_manager } from "./Start/Set_mods";
import { Start } from "./Start/start";
import { Initiate_tower_rules } from "./Start/tower_rules";
import { Rules, Tower, Tower_rules } from "./data/Tower";
import { Units } from "./data/Unit";
import { rl } from "./data/importdata";
import Game from "./game/game";
import Initialisation from "./initialisation/initialisation";
import { Add_hero, Create_hero, hero_list } from "./initialisation/initialisation_hero";

Start();