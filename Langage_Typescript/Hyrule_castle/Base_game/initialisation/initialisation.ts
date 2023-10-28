import { Add_hero, Create_hero } from "./initialisation_hero";
import { Initiat_floor } from "./initialisation_tower";

export default function Initialisation() {
  const tower = Initiat_floor();
  const firsthero = Create_hero("Link");
  Add_hero(firsthero);
  return tower;
}
