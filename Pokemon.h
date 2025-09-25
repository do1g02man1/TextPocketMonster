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
    std::vector<SkillData> Skills; // �⺻ ��ų 2�� ����
    int BaseStats[4];    // HP, Attack, Defense, Speed
    int EvolutionLevel;
    std::string EvolutionName;
    bool IsStarter;      // ��Ÿ�� ����
    bool IsWild;         // �߻����� ���� ���� ����
};

extern std::vector<PokemonData> AllPokemonData;

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

    // ���� ����
    void LearnSkill(std::shared_ptr<ISkill> Skill, int Index);
    void UseSkill(int Index, Pokemon& Target);
    void TakeDamage(int InAmount);
    bool IsFainted() const;

    // ���� ����
    void AssignDefaultSkills(const PokemonData& Data);
    void GainExp(int exp);
    void LevelUp();

    // Getter
    std::shared_ptr<ISkill> GetSkill(int Index) const;
    std::string GetName() const { return Name; }
    int GetAttack() const { return Attack; }
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
    int CurrentHP;   // ���� �� ���ϴ� HP
    int MaxHP;       // ���� HP, ���� ������ ����
    int Attack;
    int Defense;
    int Speed;
    static const int MaxSkills = 4;
    std::shared_ptr<ISkill> Skills[MaxSkills];
    int SkillCount; 
};
