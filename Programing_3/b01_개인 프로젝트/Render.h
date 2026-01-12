#pragma once
#include "Player.h"
#include "Monster.h"
#include <vector>

class Render
{
public:
    static void Draw(const Player& p, const std::vector<Monster>& m);
};
