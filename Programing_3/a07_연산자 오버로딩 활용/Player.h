#pragma once

#include "Pos.h"

class Player
{
private:
	Pos* pos;
public:
	Player();
	Player(Pos* pos);
	Player(const Player& other);
	Player(Player&& rhs);
	~Player();

	void Move(int x, int y);
	void Teleport(Pos* other_pos);

	Pos& get_pos() const; //  const Player -> 함수 실행
	void display_pos() const;
};

