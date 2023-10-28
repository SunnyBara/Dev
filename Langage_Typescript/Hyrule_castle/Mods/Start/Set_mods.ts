import { rl } from "../data/importdata";
import Start from "./start";
import { Tower_rules } from "./tower_rules";

export function Mod_manager(tower_rules: Tower_rules) {
  const tab: string[] = ["Combat Option", "Characteristics Options"];
  const answers = rl.keyInSelect(
    tab,
    `Choose your Mods\nAll mods are disable by default`,
    {
      cancel: "Back to the menu",
    }
  );
  switch (answers) {
    default:
      Set_up_mods(tower_rules, tab[answers]);
      break;
    case -1:
      Start();
      return;
  }
  return;
}

function Set_up_mods(tower_rules: Tower_rules, mod_name: string) {
  switch (mod_name.toLowerCase()) {
    case "combat option":
      console.log(
        tower_rules.better_combat_options.set
          ? "One or more options is currently active"
          : "Combats Options are currently disabled"
      );
      break;
    case "characteristics options":
      console.log(
        tower_rules.basic_characteristics.set
          ? "One or more options is currently active"
          : "Characteristics options are currently disabled"
      );
      break;
  }
  Manage_mod(tower_rules, mod_name);
}

export function Manage_mod(tower_rules: Tower_rules, mod_name: string) {
  const tab: string[] = [
    `Disable all ${mod_name}`,
    `Active all ${mod_name}`,
    `Choose`,
  ];
  const answers = rl.keyInSelect(tab, `What do you want to do ?`, {
    cancel: "Back to the menu",
  });
  switch (answers) {
    case 0:
      Switch_mods(mod_name, false, tower_rules);
      break;
    case 1:
      Switch_mods(mod_name, true, tower_rules);
      break;
    case 2:
      Choose_your_mods(mod_name, tower_rules);
      break;
    case -1:
      Start();
      return;
  }
  return;
}

export function Switch_mods(
  mod_name: string,
  change: boolean,
  tower_rules: Tower_rules
) {
  switch (mod_name) {
    case "characteristics options":
      tower_rules.basic_characteristics.character_creation = change;
      tower_rules.basic_characteristics.level_and_experience = change;
      tower_rules.basic_characteristics.basic_characteristics_II = change;
      break;

    case "combat option":
      tower_rules.better_combat_options.inventory = change;
      tower_rules.better_combat_options.magic_skills = change;
      tower_rules.better_combat_options.team_combat = change;
      break;
  }
  return;
}

export function Choose_your_mods(mod_name: string, tower_rules: Tower_rules) {
  switch (mod_name) {
    case "characteristics options":
      const mods = rl.keyInSelect(
        [
          "character_creation",
          "level_and_experience",
          "basic_characteristics_II",
        ],
        `What do you want to do ?`,
        {
          cancel: "Back to the menu",
        }
      );
      switch (mods) {
        case 0:
          tower_rules.basic_characteristics.character_creation =
            !tower_rules.basic_characteristics.character_creation;
          console.log(
            `character_creation`,
            tower_rules.basic_characteristics.character_creation
              ? `is active`
              : "is disable"
          );
          break;
        case 1:
          tower_rules.basic_characteristics.level_and_experience =
            !tower_rules.basic_characteristics.level_and_experience;
          console.log(
            `level_and_experience`,
            tower_rules.basic_characteristics.level_and_experience
              ? `is active`
              : "is disable"
          );
          break;
        case 2:
          tower_rules.basic_characteristics.basic_characteristics_II =
            !tower_rules.basic_characteristics.basic_characteristics_II;
          console.log(
            `basic_characteristics_II`,
            tower_rules.basic_characteristics.basic_characteristics_II
              ? `is active`
              : "is disable"
          );
          break;
        case -1:
          Start();
          return;
      }
      break;

    case "combat option":
      const answers = rl.keyInSelect(tab, `What do you want to do ?`, {
        cancel: "Back to the menu",
      });
      switch (answers) {
        case 0:
          Switch_mods(mod_name, false, tower_rules);
          break;
        case 1:
          Switch_mods(mod_name, true, tower_rules);
          break;
        case 2:
          Choose_your_mods(mod_name, tower_rules);
          break;
        case -1:
          Start();
          return;
      }
      break;
  }
  return;
}
