#pragma once
#include <string>

enum class PokemonType {
    Fire,
    Water,
    Grass,
    Chaos
};

enum class PokemonRole {
    Attack,
    Balance,
    Defense
};

class ISkill {
public:
    virtual std::string GetName() const = 0;
    virtual int GetPower() const = 0;
    virtual int GetAccuracy() const = 0;
    virtual PokemonType GetType() const = 0;
    virtual ~ISkill() = default;
};