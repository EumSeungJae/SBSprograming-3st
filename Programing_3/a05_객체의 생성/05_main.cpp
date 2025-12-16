#include "Account.h"


void Example(Account account) {
	cout << "예시" << endl;
}

int main() {
	cout << "생성자 호출" << endl;
	
	Account acc1;		// 기본 생성자
	Account acc2(10000);// 중첩 정의 생성자
	Account acc3(acc2);	// 

	Example(std::move(acc3));	// 임시 객체로 만드는 방법

	cout << "\n 겟터 셋터 함수 사용 예제" << endl;

	cout << "acc 계좌의 잔금 : " << acc1.get_money() << endl;

	cout << "예금할 금액을 입력해주세요" << endl;
	int temp = -1000;
	acc1.deposit(temp);
	cout << "acc 계좌의 잔금 : " << acc1.get_money() << endl;
	int amount = acc1.withDraw(2500);
	cout << "acc 계좌의 잔금 : " << acc1.get_money() << endl;

}