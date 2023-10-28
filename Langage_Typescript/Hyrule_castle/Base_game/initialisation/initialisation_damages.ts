import { Damages } from "../data/Damages";

export default function Init_damages(): Damages {
  let damages: Damages = {
    damages: 0,
    Crit: false,
    Glancing: false,
    Crushing: false,
  };
  return damages;
}
