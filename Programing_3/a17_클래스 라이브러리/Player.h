#pragma once

#include "GameObject.h"

class Player : public BattleObject
{

public:
	Player(int id, int hp, int atk);
	Player();

	void Attack(BattleObject* mon)  override;
	bool isDeath();
};

