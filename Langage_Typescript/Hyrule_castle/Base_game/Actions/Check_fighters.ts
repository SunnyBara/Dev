import { Units } from "../data/Unit";

export function Checkteamalive(teamlist: Units[]) {
  if (teamlist.length === 0) {
    return true;
  }
  return false;
}
