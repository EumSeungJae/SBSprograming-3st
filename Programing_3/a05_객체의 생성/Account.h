#pragma once	// << 애뭐임?
				// 중복으로 선언된 명령문이 있다면 한번만 선언하라

using namespace std;

// #ifndef _Account
// #define _Account
// class Account
// {
// private:
// 
// };
// #endif // !_Account

#include<iostream>

// 어떤 데이터를 저장해야 하는가? 멤버 변수

// 어떤 기능을 처리하는가? withdraw(인출) deposit(저축)

// 클래스와 함께 사용하면 좋은 키워드

// Getter Setter 함수 표현
// 기본으로 주는 금액을 1000 -> 10000

class Account {
private:
	static constexpr int default_money = 10000;
	int money; //currency;
	int* iptr;	

public:
	

	Account();				// 기본 생성자
	Account(int money);		// 중첩 정의 생성자 OverLoad constructor
	Account(const Account& other);	// 복사 생성자 copy constructor
	Account(Account&& other) noexcept;	// 이동 생성자 move
	~Account();

	// getter setter 함수를 만드세요
	int get_money() const {

		return money;
	}
	
	void set_money(int currency) {

		money = currency;
		if (money < 0) { money = 0; }
	}

	// (기능) 멤버 함수, 메소드 (method)
	int withDraw(int amount);

	void deposit(int amont);

	// 연산자 오버로딩

};

