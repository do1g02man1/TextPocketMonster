#include "Pokemon.h"
#include "Battle.h"

// SkillData 벡터를 올바르게 생성자에 전달하도록 PokemonData 초기화 방식 수정
std::vector<PokemonData> AllPokemonData = {
    {"불꽃숭이", PokemonType::Fire, PokemonRole::Attack,
        {{"불꽃세례", 40, 90, PokemonType::Fire}, {"화염방사", 90, 75, PokemonType::Fire}},
        {45, 60, 40, 65}, 16, "파이숭이"},
    {"파이숭이", PokemonType::Fire, PokemonRole::Attack,
        {{"화염방사", 90, 75, PokemonType::Fire}, {"불대문자", 110, 70, PokemonType::Fire}},
        {65, 80, 55, 80}, 36, "초염몽"},
    {"초염몽", PokemonType::Fire, PokemonRole::Attack,
        {{"불대문자", 110, 70, PokemonType::Fire}, {"화염방사", 90, 75, PokemonType::Fire}},
        {95, 110, 75, 100}, 0, ""},

    {"팽도리", PokemonType::Water, PokemonRole::Balance,
        {{"물대포", 40, 90, PokemonType::Water}, {"파도타기", 90, 75, PokemonType::Water}},
        {50, 55, 45, 60}, 16, "팽태자"},
    {"팽태자", PokemonType::Water, PokemonRole::Balance,
        {{"파도타기", 90, 75, PokemonType::Water}, {"하이드로 펌프", 110, 70, PokemonType::Water}},
        {70, 75, 60, 80}, 36, "엠페르트"},
    {"엠페르트", PokemonType::Water, PokemonRole::Balance,
        {{"하이드로 펌프", 110, 70, PokemonType::Water}, {"파도타기", 90, 75, PokemonType::Water}},
        {100, 105, 85, 100}, 0, ""},

    {"모부기", PokemonType::Grass, PokemonRole::Defense,
        {{"덩굴채찍", 45, 90, PokemonType::Grass}, {"잎날가르기", 55, 85, PokemonType::Grass}},
        {55, 50, 50, 45}, 16, "수풀부기"},
    {"수풀부기", PokemonType::Grass, PokemonRole::Defense,
        {{"잎날가르기", 55, 85, PokemonType::Grass}, {"기가드레인", 75, 80, PokemonType::Grass}},
        {75, 65, 70, 60}, 36, "토대부기"},
    {"토대부기", PokemonType::Grass, PokemonRole::Defense,
        {{"기가드레인", 75, 80, PokemonType::Grass}, {"잎날가르기", 55, 85, PokemonType::Grass}},
        {95, 85, 90, 80}, 0, ""},

    {"치코리타", PokemonType::Grass, PokemonRole::Defense,
        {{"덩굴채찍", 45, 90, PokemonType::Grass}, {"잎날가르기", 55, 85, PokemonType::Grass}},
        {45, 49, 65, 45}, 16, "베이리프"},
    {"베이리프", PokemonType::Grass, PokemonRole::Defense,
        {{"잎날가르기", 55, 85, PokemonType::Grass}, {"기가드레인", 75, 80, PokemonType::Grass}},
        {60, 62, 80, 60}, 0, ""},

    {"브케인", PokemonType::Fire, PokemonRole::Attack,
        {{"불꽃세례", 40, 90, PokemonType::Fire}, {"화염방사", 90, 75, PokemonType::Fire}},
        {55, 70, 45, 60}, 17, "마그마번"},
    {"마그마번", PokemonType::Fire, PokemonRole::Attack,
        {{"화염방사", 90, 75, PokemonType::Fire}, {"불대문자", 110, 70, PokemonType::Fire}},
        {70, 90, 60, 80}, 0, ""},

    {"꼬부기", PokemonType::Water, PokemonRole::Balance,
        {{"물대포", 40, 90, PokemonType::Water}, {"파도타기", 90, 75, PokemonType::Water}},
        {44, 48, 65, 43}, 16, "어니부기"},
    {"어니부기", PokemonType::Water, PokemonRole::Balance,
        {{"파도타기", 90, 75, PokemonType::Water}, {"하이드로 펌프", 110, 70, PokemonType::Water}},
        {59, 63, 80, 58}, 0, ""},

    {"찌르꼬", PokemonType::Normal, PokemonRole::Balance,
        {{"몸통박치기", 40, 90, PokemonType::Normal}, {"전광석화", 40, 85, PokemonType::Normal}},
        {30, 55, 30, 60}, 14, "찌르버드"},
    {"찌르버드", PokemonType::Normal, PokemonRole::Balance,
        {{"전광석화", 40, 85, PokemonType::Normal}, {"누르기", 85, 75, PokemonType::Normal}},
        {45, 75, 50, 80}, 0, ""},

    {"이브이", PokemonType::Normal, PokemonRole::Balance,
        {{"몸통박치기", 40, 90, PokemonType::Normal}, {"전광석화", 40, 85, PokemonType::Normal}},
        {55, 55, 50, 55}, 0, ""},

    {"피카츄", PokemonType::Electric, PokemonRole::Attack,
        {{"전기쇼크", 40, 90, PokemonType::Electric}, {"썬더볼트", 90, 75, PokemonType::Electric}},
        {35, 55, 40, 90}, 0, "라이츄"},
    {"라이츄", PokemonType::Electric, PokemonRole::Attack,
        {{"썬더볼트", 90, 75, PokemonType::Electric}, {"번개", 110, 70, PokemonType::Electric}},
        {60, 90, 55, 110}, 0, ""},

    {"리자드", PokemonType::Fire, PokemonRole::Attack,
        {{"불꽃세례", 40, 90, PokemonType::Fire}, {"화염방사", 90, 75, PokemonType::Fire}},
        {39, 52, 43, 65}, 16, "리자몽"},
    {"리자몽", PokemonType::Fire, PokemonRole::Attack,
        {{"화염방사", 90, 75, PokemonType::Fire}, {"불대문자", 110, 70, PokemonType::Fire}},
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
    Exp += InExp; // 경험치 누적

    while (Exp >= MaxExp)
    {
        Exp -= MaxExp;   // 초과 경험치는 다음 레벨에 적용
        LevelUp();
    }
}

void Pokemon::LevelUp()
{
    Level++; // 레벨 증가

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
//        // AllPokemonData에서 진화할 포켓몬 정보 찾기
//        for (const auto& Data : AllPokemonData)
//        {
//            if (Data.Name == NextEvolutionName)
//            {
//                Evolve(Data, AllSkillsData);
//                EvolutionLevel = Data.EvolutionLevel;
//                NextEvolutionName = Data.NextEvolutionName;
//                printf("%s(이)가 %s(으)로 진화했다!\n", Name.c_str(), Data.Name.c_str());
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
