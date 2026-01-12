#include "Battle.h"
#include <algorithm>

int Battle::CalcDamage(const Entity& atk, const Entity& def)
{
    int dmg = atk.GetStats().GetDamage() - def.GetStats().GetDamageReduction();
    return std::max(1, dmg);
}
