#include "Skill.h"

std::vector<SkillData> AllSkillsData = {
    // Normal 타입
    {"Tackle", 40, 100, PokemonType::Normal},
    {"Quick Attack", 40, 100, PokemonType::Normal},
    {"Body Slam", 85, 100, PokemonType::Normal},

    // Fire 타입
    {"Ember", 40, 100, PokemonType::Fire},
    {"Flamethrower", 90, 100, PokemonType::Fire},
    {"Fire Blast", 110, 85, PokemonType::Fire},

    // Water 타입
    {"Water Gun", 40, 100, PokemonType::Water},
    {"Surf", 90, 100, PokemonType::Water},
    {"Hydro Pump", 110, 80, PokemonType::Water},

    // Grass 타입
    {"Vine Whip", 45, 100, PokemonType::Grass},
    {"Razor Leaf", 55, 95, PokemonType::Grass},
    {"Giga Drain", 75, 100, PokemonType::Grass},

    // Electric 타입
    {"Thunder Shock", 40, 100, PokemonType::Electric},
    {"Thunderbolt", 90, 100, PokemonType::Electric},
    {"Thunder", 110, 70, PokemonType::Electric}
};