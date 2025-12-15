#pragma once
#include <iostream>
#include <string>

class Tos_Monster
{
	enum SpawnBossType {소환수, 보스};
private:
	std::string name;
	int Level;
	long long HP;
	int lineHP;

	void CalculaterLineHP() {
		lineHP = HP / 25;
	}
public:
	void ShowMonsterInfo() {
		// 실제 수치 + 줄 수
		// 실제 값을 25로 나눈 숫자를 줄로 표현하자.
		std::cout << HP << "/" << lineHP << std::endl;
	}

};

