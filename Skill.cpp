#include "Skill.h"

std::vector<SkillData> AllSkillsData = {
    // Normal 타입
    {"몸통박치기", 40, 90, PokemonType::Normal},
    {"전광석화", 40, 85, PokemonType::Normal},
    {"누르기", 85, 75, PokemonType::Normal},

    // Fire 타입
    {"불꽃세례", 40, 90, PokemonType::Fire},
    {"화염방사", 90, 75, PokemonType::Fire},
    {"불대문자", 110, 70, PokemonType::Fire},

    // Water 타입
    {"물대포", 40, 90, PokemonType::Water},
    {"파도타기", 90, 75, PokemonType::Water},
    {"하이드로 펌프", 110, 70, PokemonType::Water},

    // Grass 타입
    {"덩굴채찍", 45, 90, PokemonType::Grass},
    {"잎날가르기", 55, 85, PokemonType::Grass},
    {"기가드레인", 75, 80, PokemonType::Grass},

    // Electric 타입
    {"전기쇼크", 40, 90, PokemonType::Electric},
    {"썬더볼트", 90, 75, PokemonType::Electric},
    {"번개", 110, 70, PokemonType::Electric}
};