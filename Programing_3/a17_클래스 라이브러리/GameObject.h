#pragma once

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
	GameObject(int id);

	void SetRoomType(RoomObjectType r) { r_TYPE = r; }
};

class BattleObject : public GameObject {
protected:
	int _hp;
	int _atk;
public:
	BattleObject(int id, int hp, int atk) :
		GameObject(id), _hp(hp), _atk(atk){ }

	void Damage(int amount) { _hp -= amount; }
	bool IsDeath() { return _hp <= 0; }

	virtual void Attack(BattleObject* other);
	bool isDeath();
};


// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬)
// 고블린 클래스, 고유한 몬스터?
// 고블린 3마리랑 전투. (A) = 1 B = 2 C = 3...
// 아이템. 집행검 a()  b


