#pragma once
#include "GameObject.h"
#include <string>
#include "Player.h"

using namespace std;

class Monster : public BattleObject
{
private:
	string _name;
public:
	int GetStrength() const;

	bool operator>(const Monster* other);

	Monster(int id,int hp, int atk, string name);

	void Attack(BattleObject* other) override;

	bool isDeath();
};