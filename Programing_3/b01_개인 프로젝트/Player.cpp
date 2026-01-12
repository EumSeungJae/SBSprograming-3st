#include "Player.h"

Player::Player()
{
    x = 0; y = 10;
    level = 1; exp = 0; nextExp = 20;
    step = false; state = PlayerState::RUN;
    currentHP = stats.GetMaxHP();
}

void Player::Move() { x += 1; step = !step; state = PlayerState::RUN; }
void Player::Jump() { if (y == 10) { y = 6; state = PlayerState::JUMP; } }
void Player::Attack() { state = PlayerState::ATTACK; }

PlayerState Player::GetState() const { return state; }
char Player::GetStepChar() const { return step ? 'R' : 'P'; }

void Player::GainExp(int v) { exp += v; }
bool Player::CanLevelUp() const { return exp >= nextExp && level < 10; }

void Player::LevelUp()
{
    exp -= nextExp; level++;
    nextExp = int(nextExp * 1.2f);
}
