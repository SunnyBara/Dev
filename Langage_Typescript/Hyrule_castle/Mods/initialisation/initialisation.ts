import { Tower_rules } from "../Start/tower_rules";
import { Add_hero, Create_hero } from "./initialisation_hero";
import { Initiat_floor } from "./initialisation_tower";

export default function Initialisation(tower_rules: Tower_rules) {
  const tower = Initiat_floor();
  Init_hero(tower_rules);
  return tower;
}
