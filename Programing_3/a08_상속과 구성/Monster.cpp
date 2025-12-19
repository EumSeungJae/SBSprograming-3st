#include "Monster.h"

Monster::Monster()
{
	mov = new Moveable;
}

Monster::~Monster()
{
	delete mov;
}

void Monster::Move(int x, int y)
{
	mov->Move(x, y);
}

void Monster::Teleport(Pos* other)
{
	mov->Teleport(other);
}

void Monster::display_pos()
{
	cout << "ÁÂÇ¥ : " << mov->get_pos();
}