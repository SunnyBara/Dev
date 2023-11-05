export function Random_rarity() {
  const rand: number = Math.floor(Math.random() * 100);
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
  let rarity = Random_rarity();
  let hero: number = Choose_hero(rarity, avaible_hero_list);
  return hero;
}

export function Choose_hero(rarity : number, avaible_hero_list : number[]) : number {
  avaible_hero_list.sort((a,b) => b -a );
  if(avaible_hero_list.length !== 0) {
    let found = avaible_hero_list.find((hero_rarity) => {
      return(hero_rarity <= rarity);
    });
    while (found === undefined) {
      rarity +=1;
      found = avaible_hero_list.find((hero_rarity) => {
        return(hero_rarity <= rarity);
      });
    }

    if (found === undefined) {
      found = 0;
    }
    avaible_hero_list.splice(avaible_hero_list.indexOf(found),1);
    return(found)
  } else {
    return(0);
  }
}