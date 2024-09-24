// import { Stats } from "fs";
// import { Damage } from "./CalculDamages/calculDamge";
// import { QueryBuilder, queryBuilder } from "./Query/QueryBuilder";
// import { Eni } from "./Templates/eni";
// import { stats } from "./Templates/stats";
// import { Enumitem, Item, Stuff } from "./Templates/stuff";

// let eni = new Eni(30);
// eni.showStates();
// eni.spelldamages();
// const stuff = new Stuff();
// async function main() {
//   const itemList = await queryBuilder.execQuery();
//   for (const item of itemList) {
//     stuff.additem(item, item.type);
//   }
//   // stuff.calcGlobalStat();
//   // eni.buildStat(stuff);
//   // eni.showStates();
//   // eni.spelldamages();
//   stuff.showStuff();
// }
// // main();
// //combinaison();
// async function combinaison() {
//   const ringlist = await queryBuilder.findItem(Enumitem.Anneau).execQuery();
//   const cloacklist = await queryBuilder.findItem(Enumitem.Cape).execQuery();
//   const hatlist = await queryBuilder.findItem(Enumitem.Chapeau).execQuery();
//   const bootslist = await queryBuilder.findItem(Enumitem.Bottes).execQuery();
//   const necklist = await queryBuilder.findItem(Enumitem.Amulette).execQuery();
//   const beltlist = await queryBuilder.findItem(Enumitem.Ceinture).execQuery();
//   const weaponlist = await queryBuilder.findWeapon().execQuery();
//   for (const belt of beltlist) {
//     stuff.additem(belt, belt.type);
//     for (const ring1 of ringlist) {
//       stuff.additem(ring1, ring1.type);
//       for (const cloack of cloacklist) {
//         stuff.additem(cloack, cloack.type);
//         for (const hat of hatlist) {
//           stuff.additem(hat, hat.type);
//           for (const boots of bootslist) {
//             stuff.additem(boots, boots.type);
//             for (const neck of necklist) {
//               stuff.additem(neck, neck.type);
//               for (const weapon of weaponlist) {
//                 stuff.additem(weapon, weapon.type);
//                 let i = 0;
//                 for (const ring2 of ringlist) {
//                   if (ring2.pano == false || ring2.name != ring1.name) {
//                     stuff.additem(ring2, ring2.type);
//                     // console.log(ring2.name);
//                     console.log("////NEW STUFFF/////");
//                     stuff.showStuffName();
//                     if (i == 2) {
//                       return;
//                     }
//                     i++;
//                   }
//                 }
//               }
//             }
//           }
//         }
//       }
//     }
//   }
// }
// function recur_spell(pa, map, results) {
//   if (pa <= 1) {
//     results.add(map.toString());
//   }
//   if (pa >= 5) {
//     map[0] += 1;
//     recur_spell(pa - 5, map, results);
//     map[0] -= 1;
//   }
//   if (pa >= 4) {
//     map[1] += 1;
//     recur_spell(pa - 4, map, results);
//     map[1] -= 1;
//   }
//   if (pa >= 3) {
//     map[2] += 1;
//     recur_spell(pa - 3, map, results);
//     map[2] -= 1;
//   }
//   if (pa >= 2) {
//     map[3] += 1;
//     recur_spell(pa - 2, map, results);
//     map[3] -= 1;
//   }
// }

// function ability() {
//   const map = [0, 0, 0, 0];
//   const results = new Set();
//   recur_spell(6, map, results);
//   const setIter = results[Symbol.iterator]();
//   let check = 1;
//   while (check) {
//     // const spellcosttwo= set[3];
//     // const spellcostthree=
//     // const spellcostfour=
//     // const spellcostfive=
//     check = setIter.next().value;
//   }
// }

// // ability();
// const statsOuga = new stats();
// statsOuga.Agilité = 641 + 113;
// statsOuga.Intelligence = 1189 - 10;
// statsOuga.Dommage = 126 + 40 - 1;
// statsOuga.DommagePercent = 270 + 200;
// console.log("Ouga");
// rekopDamages(statsOuga);
// const statsRasboulaire = new stats();
// statsRasboulaire.Agilité = 641 + 113;
// statsRasboulaire.Intelligence = 1189 - 10;
// statsRasboulaire.Dommage = 126 - 18 + 12 + 40 - 1;
// statsRasboulaire.DommagePercent = 270 - 80 + 200;
// console.log("Rasboule");
// rekopDamages(statsRasboulaire);
// function rekopDamages(stuff: stats) {
//   let damages = 0;
//   damages += Damage.damage(stuff, 12, "Best");
//   damages += Damage.damage(stuff, 12, "Best");
//   damages += Damage.damage(stuff, 10, "Intelligence");
//   damages += Damage.damage(stuff, 10, "Agilité");
//   console.log(damages);
// }


let damage: number = Math.floor(
  19 +
    19 * ((287 + 1374) / 100) +
    76
);
console.log(damage);