// import { Initiate_tower_rules, Tower_rules } from "./Start/tower_rules";
// import { rl } from "./data/importdata";



//  function Local_Start() {
//   console.clear();
//   let tower_rules: Tower_rules = Initiate_tower_rules();
//   const tab: string[] = ["New game", "Optionnal Mods"];
//   const answers = rl.keyInSelect(tab, `Welcome !`, {
//     cancel: "Quit",
//   });
//   switch (answers) {
//     case 0:
//         Local_Set_up_game_rules(tower_rules);
//     //   Choose_size_of_tower(tower_rules);
//     //   Initialisation(tower_rules);
//       break;
//     case 0:
//     //   Mod_manager(tower_rules);
//       break;

//     case -1:
//       return;
//   }
//   return;
// }

// function Local_Set_up_game_rules(tower_rules: Tower_rules) {
//   const tab: string[] = ["Normal", "Difficult", "Insane"];
//   const answers = rl.keyInSelect(tab, `Choose your difficultie`, {
//     cancel: "Back to the menu",
//   });
//   switch (answers) {
//     default:
//       tower_rules.difficultie = tab[answers];
//       break;
//     case -1:
//       return;
//   }
//   return;
// }
// function Local_Choose_size_of_tower(tower_rules: Tower_rules) {
//   const tab: string[] = ["10", "20", "50", "100"];
//   const answers = rl.keyInSelect(tab, `Choose your difficultie`, {
//     cancel: "Back to the menu",
//   });
//   switch (answers) {
//     default:
//       tower_rules.size = parseInt(tab[answers]);
//       break;
//     case -1:
//       return;
//   }
//   return;
// }

// Local_Start()
window.open();