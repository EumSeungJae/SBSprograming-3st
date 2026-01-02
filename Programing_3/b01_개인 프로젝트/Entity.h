#pragma once

class EntityStats {
private:
    int Power;
    int Speed;
    
    int gain
}entityStats;

struct EntityPower {
    int ATK;
    int MATK;
    int DEF;
    int MDEF;
    int SPEED;
    int DOGE;
    int HIT;
}entityPower;

struct EntityPos {
    int x;
    int y;
}entityPos;

class Player : EntityStats {
private:
	int level;
	float Now_exp;
	float Max_exp;

	int Max_hp;
    int Max_mp;

    int x;

	EntityStats stats;

protected:
    int Current_hp;
    int current_mp;
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
