import { Tower_rules } from "../data/Tower";
import { Initiate_tower } from "./init_tower_template";
import { Init_hero } from "./initialisation_hero";
import { Initiat_floor } from "./initialisation_tower";

export default function Initialisation(tower_rules: Tower_rules) {
  Initiate_tower(tower_rules)
  const tower = Initiat_floor();
  Init_hero();
  return tower;
}
  