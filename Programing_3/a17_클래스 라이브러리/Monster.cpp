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
Monster::Monster(int id, RoomObjectType TYPE, int hp, int atk, string name)
    : BattleObject(id,TYPE,hp,atk),_name(name)
{
}
void Monster::Attack(BattleObject* other)
{
    other->Damage(_atk);
}
