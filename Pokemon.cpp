#include "Pokemon.h"

// SkillData 벡터를 올바르게 생성자에 전달하도록 PokemonData 초기화 방식 수정
std::vector<PokemonData> AllPokemonData = {
    {"불꽃숭이", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {45, 60, 40, 65}, 16, "파이숭이", true, true},
    {"팽도리", PokemonType::Water, PokemonRole::Balance,
        {{"Water Gun", 40, 100, PokemonType::Water}, {"Surf", 90, 100, PokemonType::Water}},
        {50, 55, 45, 60}, 16, "팽태자", true, true},
    {"모부기", PokemonType::Grass, PokemonRole::Defense,
        {{"Vine Whip", 45, 100, PokemonType::Grass}, {"Razor Leaf", 55, 95, PokemonType::Grass}},
        {55, 50, 50, 45}, 16, "수풀부기", true, true},
    {"치코리타", PokemonType::Grass, PokemonRole::Defense,
        {{"Vine Whip", 45, 100, PokemonType::Grass}, {"Razor Leaf", 55, 95, PokemonType::Grass}},
        {45, 49, 65, 45}, 16, "베이리프", false, true},
    {"브케인", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {55, 70, 45, 60}, 17, "마그마번", false, true},
    {"꼬부기", PokemonType::Water, PokemonRole::Balance,
        {{"Water Gun", 40, 100, PokemonType::Water}, {"Surf", 90, 100, PokemonType::Water}},
        {44, 48, 65, 43}, 16, "어니부기", false, true},
    {"찌르꼬", PokemonType::Normal, PokemonRole::Balance,
        {{"Tackle", 40, 100, PokemonType::Normal}, {"Quick Attack", 40, 100, PokemonType::Normal}},
        {30, 55, 30, 60}, 14, "찌르버드", false, true},
    {"이브이", PokemonType::Normal, PokemonRole::Balance,
        {{"Tackle", 40, 100, PokemonType::Normal}, {"Quick Attack", 40, 100, PokemonType::Normal}},
        {55, 55, 50, 55}, 0, "", false, true},
    {"피카츄", PokemonType::Electric, PokemonRole::Attack,
        {{"Thunder Shock", 40, 100, PokemonType::Electric}, {"Thunderbolt", 90, 100, PokemonType::Electric}},
        {35, 55, 40, 90}, 0, "라이츄", false, true},
    {"리자드", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {39, 52, 43, 65}, 16, "리자몽", false, true}
};

void Pokemon::LearnSkill(std::shared_ptr<ISkill> InSkill, int Index)
{
    if (Index >= 0 && Index < MaxSkills)
    {
        Skills[Index] = InSkill;
    }
}

void Pokemon::TakeDamage(int InAmount)
{
    CurrentHP -= InAmount;
	if (CurrentHP < 0) CurrentHP = 0;
}

bool Pokemon::IsFainted() const
{
	return CurrentHP <= 0;
}

void Pokemon::AssignDefaultSkills(const PokemonData& Data)
{
    SkillCount = 0;

    for (const auto& SkillInfo : Data.Skills)
    {
        if (SkillCount >= MaxSkills) break;
        Skills[SkillCount++] = std::make_shared<Skill>(SkillInfo);
    }

    for (int i = SkillCount; i < MaxSkills; i++)
        Skills[i] = nullptr;
}

std::shared_ptr<ISkill> Pokemon::GetSkill(int Index) const
{
    if (Index >= 0 && Index < MaxSkills)
    {
        return Skills[Index];
    }
    return nullptr;
}
