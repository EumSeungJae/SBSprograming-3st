#pragma once

#include "Entity.h"

class Battle
{
public:
    static int CalcDamage(const Entity& atk, const Entity& def);
};
