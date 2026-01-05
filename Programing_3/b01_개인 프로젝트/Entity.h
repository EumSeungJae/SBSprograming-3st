#pragma once

#include <iostream>
#include <string>

enum class MoveType : int
{
	Normal = 0,
	Jump = 1,
	Dash = 2
};

class EntityStats {
private:
	int _Max_hp;
	int _Now_hp;

	int _Power;
	int _Speed;

	int _Gold;

	int _Pos_x;
	int _Pos_y;

public:
	EntityStats(
		int Max_hp, int Now_hp,
		int Power, int Speed, int Gold,
		int Pos_x, int Pos_y) :
		_Max_hp(Max_hp), _Now_hp(Now_hp),
		_Power(Power), _Speed(Speed), _Gold(Gold),
		_Pos_x(Pos_x), _Pos_y(Pos_y) {}

	virtual ~EntityStats() {}

	virtual void Move();
	
};

class Run
{
public:
	int x;
	int y;
	int speed;
	MoveType moveType;

	Run(int _x, int _y, int _speed)
		: x(_x), y(_y), speed(_speed), moveType(MoveType::Normal)
	{
	}

	virtual ~Run() {}

	// ===== 추가된 함수 =====
	virtual void move()
	{
		std::cout << "Run합니다." << std::endl;
	}
};

class Dash : public Run
{
public:
	int dashPower;

	Dash(int _x, int _y, const std::string& _shape, int _speed, int _dashPower)
		: Run(_x, _y, _shape, _speed), dashPower(_dashPower)
	{
		moveType = MoveType::Dash;
	}

	void move() override
	{
		std::cout << "Dash합니다. 대시력: " << dashPower << std::endl;
	}
};


class Jump : public Run
{
public:
	int jumpPower;

	Jump(int _x, int _y, const std::string& _shape, int _speed, int _jumpPower)
		: Run(_x, _y, _shape, _speed), jumpPower(_jumpPower)
	{
		moveType = MoveType::Jump;
	}

	void move() override
	{
		std::cout << "Jump합니다. 점프력: " << jumpPower << std::endl;
	}
};


#include "rapidjson/document.h"

class RunFactory
{
public:
	static Run* CreateFromJson(const rapidjson::Value& value)
	{
		// ===== 공통 데이터 =====
		int x = value["x"].GetInt();
		int y = value["y"].GetInt();
		std::string shape = value["shape"].GetString();
		int speed = value["speed"].GetInt();

		// int → enum 형변환
		MoveType type =
			static_cast<MoveType>(value["moveType"].GetInt());

		// ===== 타입별 생성 =====
		switch (type)
		{
		case MoveType::Normal:
			return new Run(x, y, shape, speed);

		case MoveType::Jump:
		{
			int jumpPower = value["jumpPower"].GetInt();
			return new Jump(x, y, shape, speed, jumpPower);
		}

		case MoveType::Dash:
		{
			int dashPower = value["dashPower"].GetInt();
			return new Dash(x, y, shape, speed, dashPower);
		}

		default:
			return nullptr;
		}
	}
};

class Player : public EntityStats, public {
private:
	int level;
	float Now_exp;
	float Max_exp;

	EntityStats stats;

public:
	Player(int level, float Now_exp, float Max_exp,
		int Max_hp, int Now_hp, int Power, int Speed,
		int Gold, int Pos_x, int Pos_y
	);

	// 상태
	bool IsAlive() const;

	// 이동
	void Move();
	void Jump();
	void Fall();

	// 전투
	void TakeDamage(int damage);
	int Attack() const;

	// 경험치
	void GainExp(float amount);
	void LevelUp();

	// 출력용
	void PrintStatus() const;

	// 위치
	int GetPositionX() const;
	int GetFloor() const;


};

enum class MonsterType {
	WEAK,
	NORMAL,
	STRONG
};

class Monster {
private:
	MonsterType type;
	int level;
	int hp;
	int attack;

	int positionX;
	int floor;

public:
	Monster(MonsterType type, int level);

	bool IsAlive() const;

	void TakeDamage(int damage);
	int GetAttack() const;

	float GetExpMultiplier() const;

	MonsterType GetType() const;
	int GetPositionX() const;
	int GetFloor() const;

	void Print() const;
};
