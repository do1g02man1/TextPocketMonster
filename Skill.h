#pragma once
#include "ISkill.h"
#include <vector>

struct SkillData
{
    std::string Name;
    int Power;
    int Accuracy;
    PokemonType Type;
};

extern std::vector<SkillData> AllSkillsData;

class Skill : public ISkill
{
public:
    Skill(const SkillData& Data) 
        : Name(Data.Name), Power(Data.Power), Accuracy(Data.Accuracy), Type(Data.Type) {}
    std::string GetName() const override { return Name; }
    int GetPower() const override { return Power; }
    int GetAccuracy() const override { return Accuracy; }
    PokemonType GetType() const override { return Type; }

private:
    std::string Name;
    int Power;
    int Accuracy;
    PokemonType Type;
};

