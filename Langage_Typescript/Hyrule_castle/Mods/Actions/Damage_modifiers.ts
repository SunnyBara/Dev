import {
    Search_class,
    Search_class_advantage,
    Search_race_advantage,
  } from "../Search/search_functions";
  import { Damages } from "../data/Damages";
  import { Units } from "../data/Unit";
  import Init_damages from "../initialisation/initialisation_damages";
  
  export function Damage_modif(
    unit: Units,
    target: Units,
    damage: Damages,
    type: string
  ): number {
    damage.damages = Is_crit(damage, unit);
    damage.damages = Is_magic_or_physical(target, damage, type);
    damage.damages = Is_advantage_or_weak(target, damage, unit);
    damage.damages = Is_it_fear(unit, damage);
    damage.damages = Is_it_weak(target, damage);
    damage.damages = Is_it_on_def(target, damage);
    return Math.floor(damage.damages*1);
  }
  
  function Is_crit(damage: Damages, unit: Units) {
    if (unit.characteristics.luck + 5 >= Math.floor(Math.random() * 100)) {
      damage.damages *= 2;
      damage.Crit = true;
    }
    return damage.damages;
  }
  
  function Is_magic_or_physical(
    target: Units,
    damage: Damages,
    type: string
  ): number {
    if (type === "magic") {
      damage.damages =
        damage.damages - (damage.damages * target.characteristics.res) / 100;
    } else {
      damage.damages =
        damage.damages - (damage.damages * target.characteristics.def) / 100;
    }
    return damage.damages;
  }
  
  function Is_it_fear(unit: Units, damage: Damages) {
    if (unit.fighting_status.fear === true) {
      damage.damages = damage.damages / 2;
    }
    return damage.damages;
  }
  
  function Is_it_weak(unit: Units, damage: Damages) {
    if (unit.fighting_status.weakened === true) {
      damage.damages = damage.damages * 1.5;
      damage.Crushing = true;
    }
    return damage.damages;
  }
  
  function Is_it_on_def(unit: Units, damage: Damages) {
    if (unit.fighting_status.def_stance === true) {
      damage.damages = damage.damages / 2;
      damage.Glancing = true;
    }
    return damage.damages;
  }
  
  
  function Is_advantage_or_weak(
    target: Units,
    damage: Damages,
    unit: Units
  ) {
    let classes_unit: any = Search_class(unit.base_stats.class);
  
    if (Search_race_advantage(classes_unit.strengths, target.base_stats.class)) {
      damage.damages += damage.damages;
      damage.Crushing = true;
    }
    if (Search_race_advantage(classes_unit.weaknesses, target.base_stats.class)) {
      damage.damages = damage.damages / 2;
      damage.Glancing = true;
    }
    if (Search_class_advantage(classes_unit.strengths, target.base_stats.class)) {
      damage.damages += damage.damages;
      damage.Crushing = true;
    }
    if (
      Search_class_advantage(classes_unit.weaknesses, target.base_stats.class)
    ) {
      damage.damages = damage.damages / 2;
      damage.Glancing = true;
    }
  
    return damage.damages;
  }
  export function Attack(unit: Units, target : Units): Damages {
    let damages: Damages = Init_damages();
    damages.damages = unit.characteristics.str;
    damages.damages = Damage_modif(unit,target,damages,"physical");
    damages.damages = Math.floor(damages.damages*1);
    return damages;
  }