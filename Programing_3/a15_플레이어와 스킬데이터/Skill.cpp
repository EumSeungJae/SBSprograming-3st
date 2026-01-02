#include "Skill.h"
#include "Windows.h"
#include "conio.h"

bool Passive_Skill::IsAvailable()
{
	// Update 구조.  Timetick 4씩 4초마다 실행되는 패시브다

	return true;
}

void Passive_Skill::Execute()
{
	if (IsAvailable()) {
		// 로직을 실행하라
	}
}

bool Active_Skill::IsAvailable()
{
	// 플레이어가 입력을 했을 때
	// 쿨타임이 아닐 때

	return false;
}


void Active_Skill::Execute()
{
	if (IsAvailable()) {
		// 로직을 실행하라
	}
}

void Garen_Passive::Execute()
{
	cout << " 가렌이 8초 동안 피해를 입지 않거나 적의 스킬에 맞지 않으면\n"
		<< "5초마다 최대체력의 일정 비율만큼 회복합니다."
		<< endl;
}

bool Garen_Q::IsAvailable()
{
	timeTick++;
	if (timeTick >= coolCheck) {
		timeTick = 0;
		return true;
	}

	return false;
}


void Garen_Q::Execute()
{
	if (IsAvailable()) {
		cout << "가렌에게 적용된 모든 둔화 효과가 제거되고 일정 시간 동안 이동속도가 35% 상승합니다."
			<< "다음 기본 공격은 1.5초 동안 롤아이콘 - 군중제어 침묵 침묵시키고 추가 물리 피해를 입힙니다."
			<< endl;
		coolCheck = coolTime;
	}
}

bool Garen_W::IsAvailable()
{
	timeTick++;
	if (timeTick >= coolTime) {
		timeTick = 0;
		return true;
	}

	return false;
}

void Garen_W::Execute()
{
	if (IsAvailable()) {
		cout <<"W" << endl;

	}
}

bool Garen_E::IsAvailable()
{
	timeTick++;
	if (timeTick >= coolTime) {
		timeTick = 0;
		return true;
	}

	return false;
}

void Garen_E::Execute()
{
	if (IsAvailable()) {
		cout << "E" << endl;

	}
}

bool Garen_R::IsAvailable()
{
	timeTick++;
	if (timeTick >= coolTime) {
		timeTick = 0;
		return true;
	}

	return false;
}

void Garen_R::Execute()
{
	if (IsAvailable()) {
		cout << "R" << endl;

	}
}

void Player::update()
{
	if (_kbhit) {
		char key = _getch();

		switch (key) {
			
		}
	}
}
// 스킬을 습득?
void Player::setSkill(unique_ptr<Skill> skill)
{
	skills.push_back(std::move(skill));	// copy
}

void Player::useSkill(int index)
{
	// skills['q']->Execute();		<< paired?
	// skills['w']

	skills[index]->Execute();
}
