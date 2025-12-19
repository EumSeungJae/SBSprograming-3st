#include "Monster.h"


Monster::Monster()
{
	this->pos = new Pos;
}

Monster::Monster(Pos* pos)
{
	this->pos = new Pos;
	*(this->pos) = *pos;
}

Monster::~Monster()
{
	delete pos;
}

void Monster::Move(int x, int y)
{
	pos->Move(x, y);
}

void Monster::Teleport(Pos* other_pos)
{
	pos->Teleport(other_pos);
}

Pos& Monster::get_pos() const
{
	return *pos;
}

void Monster::display_pos() const
{
	cout << "p1ÀÇ ÁÂÇ¥ : " << this;
}
