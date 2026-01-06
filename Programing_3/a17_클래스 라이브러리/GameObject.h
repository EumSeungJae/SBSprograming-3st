#pragma once

#include <iostream>
#include <string>

using namespace std;

enum class RoomObjectType {
	BATTLE,
	TREASURE,
	REST

};

class GameObject
{
protected:
	int _id;
	RoomObjectType r_TYPE;
	// int instanceId;
public:
	GameObject(int id, RoomObjectType TYPE);

	void SetRoomType(RoomObjectType r) { r_TYPE = r; }

	virtual GameObject* GetObjectType() = 0;
};

class BattleObject : public GameObject {
protected:
	int _hp;
	int _atk;
public:
	BattleObject(int id, RoomObjectType TYPE, int hp, int atk);

	void Damage(int amount);
	bool IsDeath();

	virtual void Attack(BattleObject* other) = 0;

	virtual GameObject* GetObjectType() override;
};

class TreasureObject : public GameObject {

protected:
	int _gold;
	string _content;

public:
	TreasureObject(int id, RoomObjectType TYPE, int gold, string content);

	void GetTreasure();

	virtual GameObject* GetObjectType() override;

};


// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬)
// 고블린 클래스, 고유한 몬스터?
// 고블린 3마리랑 전투. (A) = 1 B = 2 C = 3...
// 아이템. 집행검 a()  b


