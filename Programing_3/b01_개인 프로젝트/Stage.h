#pragma once
#include "Player.h"
#include "Monster.h"
#include <vector>

class Stage
{
private:
    Player player;
    std::vector<Monster> monsters;

public:
    Stage();
    void Run();
};

