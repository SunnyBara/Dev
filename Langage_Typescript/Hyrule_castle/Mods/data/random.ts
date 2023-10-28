export function Random_rarirty() {
  const rand: number = Math.random() * 100;
  if (rand < 50) {
    return 1;
  } else if (rand < 80) {
    return 2;
  } else if (rand < 95) {
    return 3;
  } else if (rand < 99) {
    return 4;
  } else {
    return 5;
  }
}
export function Random_hero(avaible_hero_list: number[]): number {
  let rarity = Random_rarirty();
  let hero: number = Choose_hero(rarity, avaible_hero_list);
  return hero;
}
