#include "Account.h"
// delegate 생성자

Account::Account() : Account{1000}
{
}

Account::Account(int money) : money(money){
	iptr = new int;
}

Account::Account(const Account& other) : Account{ other.money } 
{
	cout << "복사 생성자 호출" << endl;

	*iptr = *other.iptr;
}

Account::Account(Account&& other) : money(other.money)
{
	cout << "이동 생성자 호출" << endl;
	// delete iptr;
	iptr = other.iptr;
	other.iptr = nullptr;
}

Account::~Account()
{
	delete iptr;
}

int Account::withDraw(int amount)
{
	// 현재 내가 가진 돈 + amount
	int temp =  get_money() - amount;
	int real = 0;
	if (get_money() < amount) {
		// 잔금이 부족해서 실행하지 마세요
		real = get_money();
	}
	set_money(temp);

	return real;
}

void Account::deposit(int amount)
{
	if (amount < 0) {
		cout << "음수 금액을 예금할 수 없습니다." << endl;
		return;
	}
	
	int temp = get_money() + amount;

	set_money(temp);
}
