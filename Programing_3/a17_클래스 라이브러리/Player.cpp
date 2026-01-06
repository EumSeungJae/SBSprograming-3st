#include "Player.h"


Player::Player(int id, RoomObjectType TYPE, int hp, int atk) 
	: BattleObject(id,TYPE, hp, atk) {}

Player::Player()
	: Player{ 1001,RoomObjectType::BATTLE, 1000, 100 } {}

void Player::Attack(BattleObject* other) {

	std::cout << "몬스터에게" << _atk << "만큼 대미지를 주었습니다." << std::endl;
	other->Damage(_atk);
}