#include "Battle.h"

int Battle::CalculateDamage(const Pokemon& Attacker, const Pokemon& Defender, const ISkill& Skill)
{
    int Level = Attacker.GetLevel();
    int Power = Skill.GetPower();
    int Attack = Attacker.GetAttack();
    int Defense = Defender.GetDefense();

    // �⺻ ���ϸ� ������ ���� �ܼ�ȭ ����
    int BaseDamage = (((2 * Level / 5 + 2) * Power * Attack / Defense) / 50) + 2;

    // �ڼ� ���� (Same Type Attack Bonus)
    double Stab = (Attacker.GetType() == Skill.GetType()) ? 1.5 : 1.0;

    // Ÿ�� ��
    double Effectiveness = GetTypeEffectiveness(Skill.GetType(), Defender.GetType());

    // ���� ���� (85% ~ 100%)
    double RandomFactor = (rand() % 16 + 85) / 100.0;

    // ���� ������
    int FinalDamage = static_cast<int>(BaseDamage * Stab * Effectiveness * RandomFactor);

    return (FinalDamage > 0) ? FinalDamage : 1; // �ּ� 1 ������
}
    
float Battle::GetTypeEffectiveness(PokemonType MoveType, PokemonType TargetType)
{
    switch (MoveType)
    {
    case PokemonType::Fire:
        if (TargetType == PokemonType::Grass) return 2.0f;
        if (TargetType == PokemonType::Water || TargetType == PokemonType::Fire) return 0.5f;
        return 1.0f;

    case PokemonType::Water:
        if (TargetType == PokemonType::Fire) return 2.0f;
        if (TargetType == PokemonType::Water || TargetType == PokemonType::Grass) return 0.5f;
        return 1.0f;

    case PokemonType::Grass:
        if (TargetType == PokemonType::Water) return 2.0f;
        if (TargetType == PokemonType::Fire || TargetType == PokemonType::Grass) return 0.5f;
        return 1.0f;

    case PokemonType::Electric:
        if (TargetType == PokemonType::Water) return 2.0f;
        if (TargetType == PokemonType::Grass || TargetType == PokemonType::Electric) return 0.5f;
        return 1.0f;

    case PokemonType::Normal:
        return 1.0f;

    case PokemonType::Chaos:
        return 0.5 + (rand() % 1001) / 1000.0;  // ȥ���� 0.5 ~ 1.5��
    }

    return 1.0f; // �⺻��
}

int Battle::CalculateWildPokemonGold(const Pokemon& EnemyPokemon)
{
    int BaseReward = 20; // �⺻ ����

    // 0.8 ~ 1.2 ���� ����
    float RandomFactor = 0.8f + static_cast<float>(rand() % 41) / 100.0f;

    float Reward = (BaseReward + EnemyPokemon.GetLevel() * 10) * RandomFactor;

    return static_cast<int>(Reward);
}

int Battle::CalculateExperience(const Pokemon& EnemyPokemon)
{
    int BaseExp = 20;
    int Level = EnemyPokemon.GetLevel();

    // 0.85 ~ 1.0 ���� ����
    float RandFactor = 0.85f + static_cast<float>(rand()) / RAND_MAX * 0.15f;

    int ExpEarned = static_cast<int>((BaseExp + Level * 5) * RandFactor);
    return ExpEarned;
}