import { Entity } from "./entity";

export class Eni extends Entity {
  path: string = "./data/eni.json";
  constructor(level: number) {
    super(level);
    this.implementEntity();
  }
}
