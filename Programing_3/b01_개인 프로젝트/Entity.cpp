#include "Entity.h"

// 기본 능력치 초기값

Stats::Stats() {
	maxHP = 3;
	attack = 1;
	speed = 1.0f;

	expGainRate = 1.0f;
	goldGainRate = 1.0f;
}