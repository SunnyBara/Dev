import { Attack } from "./Actions/Damages_management";
import {Create_hero } from "./initialisation/initialisation_hero";


const myHero = Create_hero('Link');
const my_dummy = Create_hero('Link');
my_dummy.name = 'Dummy';
Attack(myHero,my_dummy);

