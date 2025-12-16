#pragma once

class Stats {
private:
	int maxHP;
	int attack;
	float speed;

	float expGainRate;
	float goldGainRate;

public:
    // 생성자
	Stats();

    // Getter

    // 능력치 증가

};

class Player {
private:
	int level;
	float exp;
	float expToNext;

	int currentHP;

	int positionX;
	int floor;
	bool isJumping;

	Stats stats;

public:
    Player();

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
