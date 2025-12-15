#define _CRT_SECURE_NO_WARNINGS

#include "Person.h"
using namespace std;

// c vs cpp 차이점
// c 언어	= 절차 지향 언어 - 함수들로 구성된 프로그램
// cpp		= 객체 지향 언어 - 객체들로 구성된 프로그램

// c언어 프로그래밍을 하면서 겪었던 문제점
// 구조체 안의 데이터를 추가해서 사용을 해야한다.

struct Player {
	int id;
	char* name;
};

void play(Player player); 
// 프로그래밍의 확장이 어려워진다.
// 모든 객체의 정보를 알고 있어야 함수를 다룰 수 있다.
// 프로그램이 커지면 커질수록 다루기가 어려워 진다.

// 대입 연산자로 데이터를 초기화를 하고 있다.
// 참조 타입, 주소를 사용하는 데이터를 대입하면 어떤 일이 일어날까요?
// 주소 데이터를 대입한 후에 하나의 객체를 지워보세요.
// 이것을 해결하기 위한 방법?
#include <cstring> // strcpy

struct Monster {
	int id;
	int hp;
	char* name;	// 주소 에러. 초기화
};

int main() {
	Monster mon;
	mon.name = new char[100];
	strcpy(mon.name, "Orc");
	cout << mon.name << endl;

	Monster mon2;
	mon2 = mon;
	delete[] mon.name;

	// 얕은 복사 (shallow copy)	깊은 복사 (deep copy)

	cout << "3강" << endl;
	
	Person p1{};
	Person p2(20, "홍길동", "부산");
	p1.ToString();
	p2.ToString();

	Person p3(1000, 20, "김카츄", "관동");
	p3.ToString();

	Person p4(500, 5, "박카츄", "호연","건전지");
	
	// 직접 클래스를 동적할당 해보자
	Person* p_ptr = new Person(300, 21, "홍카츄", "신오", "홍시");
	delete p_ptr;


}