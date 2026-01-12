#pragma once
#include "Entity.h"

enum class PlayerState { RUN, JUMP, ATTACK };

class Player : public Entity
{
private:
    int level, exp, nextExp;
    bool step;
    PlayerState state;

public:
    Player();

    void Move();
    void Jump();
    void Attack();

    PlayerState GetState() const;
    char GetStepChar() const;

    void GainExp(int v);
    bool CanLevelUp() const;
    void LevelUp();
};
