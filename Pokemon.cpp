#include "Pokemon.h"

// SkillData ���͸� �ùٸ��� �����ڿ� �����ϵ��� PokemonData �ʱ�ȭ ��� ����
std::vector<PokemonData> AllPokemonData = {
    {"�Ҳɼ���", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {45, 60, 40, 65}, 16, "���̼���", true, true},
    {"�ص���", PokemonType::Water, PokemonRole::Balance,
        {{"Water Gun", 40, 100, PokemonType::Water}, {"Surf", 90, 100, PokemonType::Water}},
        {50, 55, 45, 60}, 16, "������", true, true},
    {"��α�", PokemonType::Grass, PokemonRole::Defense,
        {{"Vine Whip", 45, 100, PokemonType::Grass}, {"Razor Leaf", 55, 95, PokemonType::Grass}},
        {55, 50, 50, 45}, 16, "��Ǯ�α�", true, true},
    {"ġ�ڸ�Ÿ", PokemonType::Grass, PokemonRole::Defense,
        {{"Vine Whip", 45, 100, PokemonType::Grass}, {"Razor Leaf", 55, 95, PokemonType::Grass}},
        {45, 49, 65, 45}, 16, "���̸���", false, true},
    {"������", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {55, 70, 45, 60}, 17, "���׸���", false, true},
    {"���α�", PokemonType::Water, PokemonRole::Balance,
        {{"Water Gun", 40, 100, PokemonType::Water}, {"Surf", 90, 100, PokemonType::Water}},
        {44, 48, 65, 43}, 16, "��Ϻα�", false, true},
    {"���", PokemonType::Normal, PokemonRole::Balance,
        {{"Tackle", 40, 100, PokemonType::Normal}, {"Quick Attack", 40, 100, PokemonType::Normal}},
        {30, 55, 30, 60}, 14, "�����", false, true},
    {"�̺���", PokemonType::Normal, PokemonRole::Balance,
        {{"Tackle", 40, 100, PokemonType::Normal}, {"Quick Attack", 40, 100, PokemonType::Normal}},
        {55, 55, 50, 55}, 0, "", false, true},
    {"��ī��", PokemonType::Electric, PokemonRole::Attack,
        {{"Thunder Shock", 40, 100, PokemonType::Electric}, {"Thunderbolt", 90, 100, PokemonType::Electric}},
        {35, 55, 40, 90}, 0, "������", false, true},
    {"���ڵ�", PokemonType::Fire, PokemonRole::Attack,
        {{"Ember", 40, 100, PokemonType::Fire}, {"Flamethrower", 90, 100, PokemonType::Fire}},
        {39, 52, 43, 65}, 16, "���ڸ�", false, true}
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
