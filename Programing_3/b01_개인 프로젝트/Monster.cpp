#include "Monster.h"

Monster::Monster(MonsterRank r, int px)
{
    rank = r; x = px; y = 10;
    int hp = 1;
    if (r == MonsterRank::NORMAL) hp = 2;
    if (r == MonsterRank::STRONG) hp = 3;
    if (r == MonsterRank::ELITE) hp = 4;
    stats.AddMaxHP(hp - 1);
    currentHP = stats.GetMaxHP();
}

MonsterRank Monster::GetRank() const { return rank; }
