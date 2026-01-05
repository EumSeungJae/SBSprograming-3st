#include "Player.h"
#include <iostream>

Player::Player(int id, int hp, int atk) : BattleObject(id, hp, atk) {}

Player::Player()
	: Player{ 1001, 1000, 100 } {}

void Player::Attack(BattleObject* other) {

	std::cout << "몬스터에게" << _atk << "만큼 대미지를 주었습니다." << std::endl;
	other->Damage(_atk);
}