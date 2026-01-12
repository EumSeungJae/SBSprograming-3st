#pragma once
#include "Entity.h"

enum class MonsterRank { WEAK, NORMAL, STRONG, ELITE };

class Monster : public Entity
{
private:
    MonsterRank rank;

public:
    Monster(MonsterRank r, int x);

    MonsterRank GetRank() const;
};
