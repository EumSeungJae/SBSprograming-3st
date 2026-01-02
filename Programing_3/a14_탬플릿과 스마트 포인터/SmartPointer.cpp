#include "SmartPointer.h"

// 몬스터
// 클래스(drop,stat...)

void Example1() {
	cout << endl;
	std::cout << "Smart Point : Unique Example" << std::endl;
	Uex unique;
	unique.setPointer(std::make_unique<int>(10));
	unique.getValue();
	unique.setPointer(10);
	unique.getValue();

}

void Example2() {
	cout << endl;
	std::cout << "Smart Point : Shared Example" << std::endl;
	Sharedptr shared;
	Sharedptr shared2;

	shared.setPointer(10);
	shared2.setPointer(shared.sptr);
	shared.getValue();
	shared2.getValue();

	std::cout << " 공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << std::endl;
	shared.sptr.reset();
	std::cout << " 공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << std::endl;
	std::cout << " 공유 포인터가 가리키고 있는 수 : " << shared2.sptr.use_count() << std::endl;

}

void Example3() {
	cout << endl;
	std::cout << "Smart Point : Weak Example" << std::endl;

	shared_ptr<police> p1 = make_shared<police>(); // new police() 대신 사용한다;
	shared_ptr<gun> glock = make_shared<gun>();
	p1->myGun = glock; // 경찰이 소유한 총이 glock을 가리킨다
	glock->owner = p1; // 총의 소유자는 p1이다
	
	std::cout << p1->myGun.use_count() << std::endl;
	std::cout << glock->owner.use_count() << std::endl;


}