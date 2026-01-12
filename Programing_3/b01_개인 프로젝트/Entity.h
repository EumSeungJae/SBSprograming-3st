#pragma once
#include "Stats.h"

class Entity
{
protected:
    int x, y;
    int currentHP;
    Stats stats;

public:
    virtual ~Entity() = default;

    int GetX() const;
    int GetY() const;
    void SetPosition(int x, int y);

    int GetHP() const;
    int GetMaxHP() const;
    void SetHP(int hp);
    bool IsDead() const;

    Stats& GetStats();
    const Stats& GetStats() const;
};
