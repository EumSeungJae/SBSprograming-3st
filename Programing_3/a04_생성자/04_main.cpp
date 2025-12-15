#include <iostream>
#include "Monster.h"

using namespace std;

/*
*  Object Orient Programming ( OOP 에 대해 설명하시오 )
*  
*/

// const MOnster mon = mon2 ( 복제
// 몬스터의 기본값을 전달해서 새로운 객체 만들기

// 복제 ( deep copy )	1. 사용자 정의한 클래스가 raw pointer를 소유하고 있으면
//							new 키워드로 동적할당 해줘야 한다.
//						2. 없으면? 기본 복제 생성자 사용하면 된다.

void Example( Monster mon) {
	cout << "test" << endl;
}

int main() {
	cout << "4강 객체 생성자에 대한 이해" << endl;
	Monster mon1(); 
	// 생성자를 선언하지 않으면 기본(default) 생성자가 구현되어 있다.
	Monster mon2("해골수비병", 15, 0, "불경", BattleType::불경,0);
	
	Monster mon3 = Monster("해골수비병", 15, 0, "불경", BattleType::불경, 0);

	mon2.SetptrValue(10);
	Example(mon2);

	cout << "lValue vs rValue" << endl;

	int a = 10;
	int& aRef = a;		// lValue의 참조자
	int&& bRef = 10;	// Rvalue의 참조자

	// Monster mon3;
	// lValue 타입은 값을 저장하고 변경할 수 있는 타입
	// rValue 타입은 값을 변경할 수 없음. 이름을 가질 수 없음


}
