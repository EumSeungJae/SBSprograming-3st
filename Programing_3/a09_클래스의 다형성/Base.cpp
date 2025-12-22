#include "Base.h"

void Example()
{
	cout << "\nExample 예제\n" << endl;

	Base base;
	base.display();
	Derived d;
	d.display();

}

// Base		: Character
// Derived	: 전사, 마법사, 도적
void Example2()
{
	cout << "\nExample2 예제\n" << endl;

	Base* bptr = new Base;
	Derived* dptr = new Derived;
	Base* someptr = new Derived;

	bptr->display();
	dptr->display();
	someptr->display();
}

// 다형성 왜 쓰는가?
// interface 사용하는 것.

void Example4()
{
	cout << "\nExample4 예제\n" << endl;

	Idisplayable* all_display[3];	// 배열, vector
	Base* base_ptr = new Base;
	Base* d_ptr = new Derived;
	Unit* unit_ptr = new Unit;

	base_ptr->display();
	d_ptr->display();
	unit_ptr->display();


}
