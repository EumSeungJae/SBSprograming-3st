#pragma once

// 능력치 계산 전담 클래스
class Stats
{
private:
    //기초능력치
    int baseMaxHP;
    int baseDamage;
    int baseRange;
    int baseDamageReduction;

    float baseMoveSpeed;
    float baseJumpPower;

    //장비부가능력치
    int bonusMaxHP;
    int bonusDamage;
    int bonusRange;
    int bonusDamageReduction;

    float bonusMoveSpeed;
    float bonusJumpPower;

public:
    Stats();

    //최종능력치반환
    int GetMaxHP() const;
    int GetDamage() const;
    int GetRange() const;
    int GetDamageReduction() const;
    float GetMoveSpeed() const;
    float GetJumpPower() const;

    //기본능력치증가 (레벨업)
    void AddMaxHP(int value);
    void AddDamage(int value);
    void AddRange(int value);
    void AddDamageReduction(int value);
    void AddMoveSpeed(float value);
    void AddJumpPower(float value);

    //장비 장작,해제
    void ApplyEquipment(
        int hp,
        int damage,
        int range,
        int damageReduction,
        float moveSpeed,
        float jumpPower
    );

    void RemoveEquipment(
        int hp,
        int damage,
        int range,
        int damageReduction,
        float moveSpeed,
        float jumpPower
    );
};
