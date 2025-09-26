#include "Pokemon.h"
#include "Battle.h"

// SkillData ���͸� �ùٸ��� �����ڿ� �����ϵ��� PokemonData �ʱ�ȭ ��� ����
std::vector<PokemonData> AllPokemonData = {
    {"�Ҳɼ���", PokemonType::Fire, PokemonRole::Attack,
        {{"�Ҳɼ���", 40, 90, PokemonType::Fire}, {"ȭ�����", 90, 75, PokemonType::Fire}},
        {45, 60, 40, 65}, 16, "���̼���"},
    {"���̼���", PokemonType::Fire, PokemonRole::Attack,
        {{"ȭ�����", 90, 75, PokemonType::Fire}, {"�Ҵ빮��", 110, 70, PokemonType::Fire}},
        {65, 80, 55, 80}, 36, "�ʿ���"},
    {"�ʿ���", PokemonType::Fire, PokemonRole::Attack,
        {{"�Ҵ빮��", 110, 70, PokemonType::Fire}, {"ȭ�����", 90, 75, PokemonType::Fire}},
        {95, 110, 75, 100}, 0, ""},

    {"�ص���", PokemonType::Water, PokemonRole::Balance,
        {{"������", 40, 90, PokemonType::Water}, {"�ĵ�Ÿ��", 90, 75, PokemonType::Water}},
        {50, 55, 45, 60}, 16, "������"},
    {"������", PokemonType::Water, PokemonRole::Balance,
        {{"�ĵ�Ÿ��", 90, 75, PokemonType::Water}, {"���̵�� ����", 110, 70, PokemonType::Water}},
        {70, 75, 60, 80}, 36, "���丣Ʈ"},
    {"���丣Ʈ", PokemonType::Water, PokemonRole::Balance,
        {{"���̵�� ����", 110, 70, PokemonType::Water}, {"�ĵ�Ÿ��", 90, 75, PokemonType::Water}},
        {100, 105, 85, 100}, 0, ""},

    {"��α�", PokemonType::Grass, PokemonRole::Defense,
        {{"����ä��", 45, 90, PokemonType::Grass}, {"�ٳ�������", 55, 85, PokemonType::Grass}},
        {55, 50, 50, 45}, 16, "��Ǯ�α�"},
    {"��Ǯ�α�", PokemonType::Grass, PokemonRole::Defense,
        {{"�ٳ�������", 55, 85, PokemonType::Grass}, {"�Ⱑ�巹��", 75, 80, PokemonType::Grass}},
        {75, 65, 70, 60}, 36, "���α�"},
    {"���α�", PokemonType::Grass, PokemonRole::Defense,
        {{"�Ⱑ�巹��", 75, 80, PokemonType::Grass}, {"�ٳ�������", 55, 85, PokemonType::Grass}},
        {95, 85, 90, 80}, 0, ""},

    {"ġ�ڸ�Ÿ", PokemonType::Grass, PokemonRole::Defense,
        {{"����ä��", 45, 90, PokemonType::Grass}, {"�ٳ�������", 55, 85, PokemonType::Grass}},
        {45, 49, 65, 45}, 16, "���̸���"},
    {"���̸���", PokemonType::Grass, PokemonRole::Defense,
        {{"�ٳ�������", 55, 85, PokemonType::Grass}, {"�Ⱑ�巹��", 75, 80, PokemonType::Grass}},
        {60, 62, 80, 60}, 0, ""},

    {"������", PokemonType::Fire, PokemonRole::Attack,
        {{"�Ҳɼ���", 40, 90, PokemonType::Fire}, {"ȭ�����", 90, 75, PokemonType::Fire}},
        {55, 70, 45, 60}, 17, "���׸���"},
    {"���׸���", PokemonType::Fire, PokemonRole::Attack,
        {{"ȭ�����", 90, 75, PokemonType::Fire}, {"�Ҵ빮��", 110, 70, PokemonType::Fire}},
        {70, 90, 60, 80}, 0, ""},

    {"���α�", PokemonType::Water, PokemonRole::Balance,
        {{"������", 40, 90, PokemonType::Water}, {"�ĵ�Ÿ��", 90, 75, PokemonType::Water}},
        {44, 48, 65, 43}, 16, "��Ϻα�"},
    {"��Ϻα�", PokemonType::Water, PokemonRole::Balance,
        {{"�ĵ�Ÿ��", 90, 75, PokemonType::Water}, {"���̵�� ����", 110, 70, PokemonType::Water}},
        {59, 63, 80, 58}, 0, ""},

    {"���", PokemonType::Normal, PokemonRole::Balance,
        {{"�����ġ��", 40, 90, PokemonType::Normal}, {"������ȭ", 40, 85, PokemonType::Normal}},
        {30, 55, 30, 60}, 14, "�����"},
    {"�����", PokemonType::Normal, PokemonRole::Balance,
        {{"������ȭ", 40, 85, PokemonType::Normal}, {"������", 85, 75, PokemonType::Normal}},
        {45, 75, 50, 80}, 0, ""},

    {"�̺���", PokemonType::Normal, PokemonRole::Balance,
        {{"�����ġ��", 40, 90, PokemonType::Normal}, {"������ȭ", 40, 85, PokemonType::Normal}},
        {55, 55, 50, 55}, 0, ""},

    {"��ī��", PokemonType::Electric, PokemonRole::Attack,
        {{"�����ũ", 40, 90, PokemonType::Electric}, {"�����Ʈ", 90, 75, PokemonType::Electric}},
        {35, 55, 40, 90}, 0, "������"},
    {"������", PokemonType::Electric, PokemonRole::Attack,
        {{"�����Ʈ", 90, 75, PokemonType::Electric}, {"����", 110, 70, PokemonType::Electric}},
        {60, 90, 55, 110}, 0, ""},

    {"���ڵ�", PokemonType::Fire, PokemonRole::Attack,
        {{"�Ҳɼ���", 40, 90, PokemonType::Fire}, {"ȭ�����", 90, 75, PokemonType::Fire}},
        {39, 52, 43, 65}, 16, "���ڸ�"},
    {"���ڸ�", PokemonType::Fire, PokemonRole::Attack,
        {{"ȭ�����", 90, 75, PokemonType::Fire}, {"�Ҵ빮��", 110, 70, PokemonType::Fire}},
        {78, 84, 78, 100}, 0, ""}
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

void Pokemon::GainExp(int InExp)
{
    Exp += InExp; // ����ġ ����

    while (Exp >= MaxExp)
    {
        Exp -= MaxExp;   // �ʰ� ����ġ�� ���� ������ ����
        LevelUp();
    }
}

void Pokemon::LevelUp()
{
    Level++; // ���� ����

    switch (Role)
    {
    case PokemonRole::Attack:
        MaxHP += 1;
        Attack += 2;
        Defense += 1;
        Speed += 2;
        break;
    case PokemonRole::Balance:
        MaxHP += 2;
        Attack += 1;
        Defense += 1;
        Speed += 2;
        break;
    case PokemonRole::Defense:
        MaxHP += 2;
        Attack += 1;
        Defense += 2;
        Speed += 1;
        break;
    }

    //CheckEvolution(AllPokemonData, AllSkillsData);
}

//void Pokemon::Evolution()
//{
//    
//}
//
//void Pokemon::CheckEvolution(const std::vector<PokemonData>& AllPokemonData, const std::vector<SkillData>& AllSkillsData)
//{
//    if (NextEvolutionName.empty())
//        return;
//
//    if (Level >= EvolutionLevel)
//    {
//        // AllPokemonData���� ��ȭ�� ���ϸ� ���� ã��
//        for (const auto& Data : AllPokemonData)
//        {
//            if (Data.Name == NextEvolutionName)
//            {
//                Evolve(Data, AllSkillsData);
//                EvolutionLevel = Data.EvolutionLevel;
//                NextEvolutionName = Data.NextEvolutionName;
//                printf("%s(��)�� %s(��)�� ��ȭ�ߴ�!\n", Name.c_str(), Data.Name.c_str());
//                break;
//            }
//        }
//    }
//}

std::shared_ptr<ISkill> Pokemon::GetSkill(int Index) const
{
    if (Index >= 0 && Index < MaxSkills)
    {
        return Skills[Index];
    }
    return nullptr;
}
