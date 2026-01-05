#include "Monster.h"

#include <iostream>

int Monster::GetStrength() const
{
    return _hp + _atk;
}

bool Monster::operator>(const Monster* other)
{
    return GetStrength() > other->GetStrength();
}
void Monster::Attack(BattleObject* other)
{
    other->Damage(_atk);
}

void Monster::isDeath()
{
}
