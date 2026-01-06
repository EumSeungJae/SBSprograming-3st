#pragma once
#include <iostream>
#include "GameObject.h"

class Player : public BattleObject
{

public:
	Player(int id, RoomObjectType TYPE, int hp, int atk);
	Player();

	void Attack(BattleObject* mon)  override;
	
};

