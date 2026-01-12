#include "Entity.h"

int Entity::GetX() const { return x; }
int Entity::GetY() const { return y; }

void Entity::SetPosition(int x, int y) { this->x = x; this->y = y; }

int Entity::GetHP() const { return currentHP; }
int Entity::GetMaxHP() const { return stats.GetMaxHP(); }

void Entity::SetHP(int hp) { currentHP = hp < 0 ? 0 : hp; }
bool Entity::IsDead() const { return currentHP <= 0; }

Stats& Entity::GetStats() { return stats; }
const Stats& Entity::GetStats() const { return stats; }
