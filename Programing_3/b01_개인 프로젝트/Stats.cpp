#include "Stats.h"

Stats::Stats()
{
    baseMaxHP = 3; baseDamage = 1; baseRange = 2;
    baseDamageReduction = 0;
    baseMoveSpeed = 1.0f; baseJumpPower = 4.0f;

    bonusMaxHP = bonusDamage = bonusRange = bonusDamageReduction = 0;
    bonusMoveSpeed = bonusJumpPower = 0.0f;
}

int Stats::GetMaxHP() const { return baseMaxHP + bonusMaxHP; }
int Stats::GetDamage() const { return baseDamage + bonusDamage; }
int Stats::GetRange() const { return baseRange + bonusRange; }
int Stats::GetDamageReduction() const { return baseDamageReduction + bonusDamageReduction; }
float Stats::GetMoveSpeed() const { return baseMoveSpeed + bonusMoveSpeed; }
float Stats::GetJumpPower() const { return baseJumpPower + bonusJumpPower; }

void Stats::AddMaxHP(int v) { baseMaxHP += v; }
void Stats::AddDamage(int v) { baseDamage += v; }
void Stats::AddRange(int v) { baseRange += v; }
void Stats::AddDamageReduction(int v) { baseDamageReduction += v; }
void Stats::AddMoveSpeed(float v) { baseMoveSpeed += v; }
void Stats::AddJumpPower(float v) { baseJumpPower += v; }

void Stats::ApplyEquipment(int hp, int dmg, int range, int red, float ms, float jp)
{
    bonusMaxHP += hp; bonusDamage += dmg; bonusRange += range;
    bonusDamageReduction += red; bonusMoveSpeed += ms; bonusJumpPower += jp;
}
