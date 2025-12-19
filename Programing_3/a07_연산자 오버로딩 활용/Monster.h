#pragma once

#include "Pos.h"

class Monster
{
private:
	Pos* pos;
public:
	Monster();
	Monster(Pos* pos);
	Monster(const Monster& other);
	Monster(Monster&& rhs);
	~Monster();

	void Move(int x, int y);
	void Teleport(Pos* other_pos);

	Pos& get_pos() const;
	void display_pos() const;
};

