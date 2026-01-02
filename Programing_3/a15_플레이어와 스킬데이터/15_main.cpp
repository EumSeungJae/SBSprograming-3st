
// 플레이어
// 스킬

#include "Skill.h"
#include <Windows.h>
int main() {
	// 데이터를 표현한다. 데이터를 포인터로 관리한다. 스마트 포인터로 표현.
	unique_ptr<Skill> garenPassive = make_unique <Garen_Passive>();
	unique_ptr<Skill> garenQ = make_unique <Garen_Q>();
	unique_ptr<Skill> garenW = make_unique <Garen_W>();
	unique_ptr<Skill> garenE = make_unique <Garen_E>();
	unique_ptr<Skill> garenR = make_unique <Garen_R>();

	// 데이터를 사용하는 객체가 필요하다.

	Player Garen;

	Garen.setSkill(make_unique <Garen_Passive>());
	Garen.setSkill(make_unique <Garen_Q>());
	Garen.setSkill(make_unique <Garen_W>());
	Garen.setSkill(make_unique <Garen_E>());
	Garen.setSkill(make_unique <Garen_R>());

	cout << "사용스킬"<< endl;

	Garen.useSkill(2); // cin >> "Q" Q가 발동

	cout << "-----"<<endl;

	garenPassive->Execute();
	garenQ->Execute();
	garenW->Execute();
	garenE->Execute();
	garenR->Execute();

	while (true) {
		// 플레이어의 입력



		Sleep(17);
	}
}