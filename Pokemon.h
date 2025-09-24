#pragma once
#include "ISkill.h"
#include <string>
#include <memory>


class Pokemon 
{
public:
    Pokemon() = default;
    Pokemon(std::string InName, PokemonType InType, PokemonRole InRole, int InLevel)
        : Name(InName), Type(InType), Role(InRole), Level(InLevel) {}

    // 전투 관련
    void LearnSkill(std::shared_ptr<ISkill> skill);
    void UseSkill(int index, Pokemon& target);
    void TakeDamage(int amount);
    bool IsFainted() const;

    // 성장 관련
    void GainExp(int exp);
    void LevelUp();

    // Getter
    std::string GetName() const { return Name; }
    int GetHP() const;
    int GetLevel() const { return Level; }

protected:
    std::string Name;
    PokemonType Type;
    PokemonRole Role;
    int Level;
    int hp, attack, defense, speed;
    static const int MAX_SKILLS = 4;
    std::shared_ptr<ISkill> skills[MAX_SKILLS];
    int skillCount;
};
