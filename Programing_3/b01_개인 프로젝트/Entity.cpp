#include "Entity.h"

// 기본 능력치 초기값

EntityStats::entityStats(int STR, int INT, int VIT, int AGI, int DEX) :
	STR(STR),INT(INT),VIT(VIT),AGI(AGI),DEX(DEX) {}

EntityStats::entityStats()
	: EntityStats(1, 1, 1, 1, 1) {}


