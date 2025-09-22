#pragma once
#include "ISkill.h"
#include <string>
#include <memory>

class Pokemon 
{
public:
    Pokemon(std::string name, PokemonType type, PokemonRole role, int level);

    // 전투 관련
    void LearnSkill(std::shared_ptr<ISkill> skill);
    void UseSkill(int index, Pokemon& target);
    void TakeDamage(int amount);
    bool IsFainted() const;

    // 성장 관련
    void GainExp(int exp);
    void LevelUp();

    // Getter
    std::string GetName() const;
    int GetHP() const;
    int GetLevel() const;

protected:
    std::string name;
    PokemonType type;
    PokemonRole role;
    int level;
    int hp, attack, defense, speed;
    static const int MAX_SKILLS = 4;
    std::shared_ptr<ISkill> skills[MAX_SKILLS];
    int skillCount;
};
