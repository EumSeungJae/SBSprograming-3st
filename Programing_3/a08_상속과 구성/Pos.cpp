#include "Pos.h"

Pos::Pos() : Pos(0, 0) {}

Pos::Pos(int x, int y) : x(x), y(y) {}

Pos::Pos(const Pos& other) : Pos(other.x, other.y) {}

Pos::Pos(Pos&& rhs) noexcept = default;

Pos::~Pos() = default;

bool Pos::operator==(const Pos& other)
{
	return (x == other.x && y == other.y);
}

bool Pos::operator!=(const Pos& other)
{
	return !(*this == other);
}

Pos Pos::operator=(const Pos& other)
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;
	return *this;
}

ostream& operator<<(ostream& os, const Pos& pos)
{
	os << "[x : " << pos.x << ", y : " << pos.y << " ]" << endl;

	return os;
}

istream& operator>>(istream& is, Pos& pos)
{
	int x = 0, y = 0;
	cout << "x의 값 : ";
	is >> x;
	cout << "y의 값 : ";
	is >> y;

	pos = Pos{ x,y };
	return is;
}
void Pos::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Pos::Teleport(Pos* other_pos)
{
	this->x = other_pos->x;
	this->y = other_pos->y;
}
