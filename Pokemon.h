#pragma once
//#include "ISkill.h"
#include "Skill.h"
#include <string>
#include <memory>
#include <vector>

struct PokemonData {
    std::string Name;
    PokemonType Type;
    PokemonRole Role;
    std::vector<SkillData> Skills; // 기본 스킬 2개 포함
    int BaseStats[4];    // HP, Attack, Defense, Speed
    int EvolutionLevel;
    std::string NextEvolutionName;
};

extern std::vector<PokemonData> AllPokemonData;
extern struct PokemonData FinalBoss;

class Pokemon
{
public:
    Pokemon() = default;
    Pokemon(const PokemonData& InData, int InLevel)
    {
        Name = InData.Name;
        Type = InData.Type;
        Role = InData.Role;
        Level = InLevel;
        CurrentHP = InData.BaseStats[0],
            MaxHP = InData.BaseStats[0],
            Attack = InData.BaseStats[1];
        Defense = InData.BaseStats[2];
        Speed = InData.BaseStats[3];
        AssignDefaultSkills(InData);
    }

    // 전투 관련
    void LearnSkill(std::shared_ptr<ISkill> Skill, int Index);
    void TakeDamage(int InAmount);
    bool IsFainted() const;
    void Heal(int InHeal);

    // 성장 관련
    void AssignDefaultSkills(const PokemonData& Data);
    void GainExp(int InExp);
    void LevelUp();
    void Evolution();
    void CheckEvolution(const std::vector<PokemonData>& AllPokemonData, const std::vector<SkillData>& AllSkillsData);

    // Getter
    std::shared_ptr<ISkill> GetSkill(int Index) const;
    std::string GetName() const { return Name; }
    PokemonType GetType() const { return Type; }
    int GetAttack() const { return Attack; }
    int GetDefense() const { return Defense; }
    int GetCurrentHP() const { return CurrentHP; }
    int GetMaxHP() const { return MaxHP; }
    int GetLevel() const { return Level; }
    int GetSpeed() const { return Speed; }
    int GetSkillCount() const { return SkillCount; }
    std::string GetSkillName(int Index) const { return Skills[Index]->GetName(); }

private:
    std::string Name;
    PokemonType Type;
    PokemonRole Role;
    int Level;
    int CurrentHP;   // 전투 중 변하는 HP
    int MaxHP;       // 기준 HP
    int Attack;
    int Defense;
    int Speed;
    int Exp = 0;
    static const int MaxExp = 50;
    static const int MaxSkills = 4;
    std::shared_ptr<ISkill> Skills[MaxSkills];
    int SkillCount;
};
