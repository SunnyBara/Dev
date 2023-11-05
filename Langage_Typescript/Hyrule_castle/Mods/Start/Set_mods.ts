import { Mods, Tower_rules } from "../data/Tower";
import { rl } from "../data/importdata";
import { Towertemplate } from "../initialisation/init_tower_template";
import { Menu } from "./start";


export function Mod_manager(tower_rules: Tower_rules) {
  console.clear();
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
      Menu(tower_rules);
      return;
  }
  return;
}

function Set_up_mods(tower_rules: Tower_rules, mod_name: string) {
  console.clear();
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
    cancel: "Back to the Mod manager",
  });
  switch (answers) {
    case 0:
      Switch_mods(mod_name, false, tower_rules);
      Mod_manager(tower_rules);
      break;
    case 1:
      Switch_mods(mod_name, true, tower_rules);
      Mod_manager(tower_rules);
      break;
    case 2:
      Choose_your_mods(mod_name, tower_rules);
      break;
    case -1:
	  break;
  }
  return;
}

export function Switch_mods(
  mod_name: string,
  change: boolean,
  tower_rules: Tower_rules
) {
	console.clear();
  switch (mod_name.toLowerCase()) {
    case "characteristics options":
	  tower_rules.basic_characteristics.set = change;
	  tower_rules.basic_characteristics.Characteristics_mods.forEach((mod) => {
	    mod.set = change;
	    return;
	  })
      break;

    case "combat option":
	  tower_rules.better_combat_options.set = change;
	  tower_rules.better_combat_options.Combat_mods.forEach((mod) => {
	    mod.set = change;
	    return;
	  })
      break;
  }
  return;
}

export function Choose_your_mods(mod_name: string, tower_rules: Tower_rules) {
  let stop : boolean = true;
  console.clear();
  while(stop) {
 	switch (mod_name.toLowerCase()) {
      case "characteristics options":
        const Chara_tab : string[] = [];
	    tower_rules.basic_characteristics.Characteristics_mods.forEach((mods)=> {Chara_tab.push(mods.mod_name)});
	    const Char_mods = rl.keyInSelect(Chara_tab,`What do you want to do ?`,{cancel: "Back to the Mod manager",});
        switch (Char_mods) {
          default:
		    Switch_single_mods(Find_mod_by_name(tower_rules,Chara_tab[Char_mods]));
            break;
		  case -1:
			stop = false;
		    Mod_manager(tower_rules);
		    return;
  	    }
        break;
      case "combat option":
	    const Combat_tab : string[] = [];
	    tower_rules.better_combat_options.Combat_mods.forEach((mods)=> {Combat_tab.push(mods.mod_name)});
	    const Combat_mods = rl.keyInSelect(Combat_tab,`What do you want to do ?`,{cancel: "Back to the Mod manager",});
	    switch (Combat_mods) {
	      default:
	     	Switch_single_mods(Find_mod_by_name(tower_rules,Combat_tab[Combat_mods]));
		    break;
	    case -1:
		  stop = false;
      console.clear()
		  Mod_manager(tower_rules);
		  return;
        }
        break;
    }
  }
  return;
}

export function Switch_single_mods(mod : Mods | null){
  if(mod !== null){
	console.clear();
	mod.set = !mod.set;
	console.log(
	  `${mod.mod_name}`,
	  mod.set
	  ? `is active`
	  : "is disable"
	);
  }
  return;
}

export function Find_mod_by_name(tower_rules: Tower_rules,mod_name : string)
{
	
  let mod_found : Mods | null = null ;
  let find : Boolean = tower_rules.basic_characteristics.Characteristics_mods.every((mod) => {
	if(mod.mod_name === mod_name) {
	  mod_found = mod;
	  return false;
	}
	return true;
  })
  if(find) {
    tower_rules.better_combat_options.Combat_mods.every((mod)=> {
      if(mod.mod_name === mod_name) {
		mod_found = mod;
		return false;
	  }
	  return true;
	})	
  }
  return (mod_found);
}

export function findIfModIsActive(mod_name : string){

  for(const mod of Towertemplate.tower_rules.better_combat_options.Combat_mods){
    if (mod.mod_name === mod_name){
      return(mod.set)
    }
  }
  for(const mod of Towertemplate.tower_rules.basic_characteristics.Characteristics_mods){
    if (mod.mod_name === mod_name){
      return(mod.set)
    }
  }
}
