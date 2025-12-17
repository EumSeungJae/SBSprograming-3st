#include <iostream>
#include <string>
#include "Mystring.h"

using namespace std;

int main() {
	std::cout << "string 클래스를 이해해보자" << std::endl;;
	std::string str = "Hello world";
	const char* str2 = "안녕하세요";
	str = "아무말";
	cout << str << endl;
	cout << str2 << endl;

	// string 타입은 선언 후에 rvalue 타입을 대입할 수 있다.
	// 왜 이게 가능한지 구현을 통해서 알아본다.

	std::cout << "Mystring 객체 구현" << std::endl;
	Mystring s1;
	Mystring s2("Hello wold!");

	Mystring s3(s2); // copy
	Mystring s4(std::move(s3)); 
	// s3 -> str은 null, s4는 s3의 str을 갖는다. (move)

	std::cout << "Mystring 연산자를 이용한 기능 구현 (연산자 오버로딩)" << std::endl;
	Mystring s5;	// 다형성 "=" 내부적으로 실행되는 코드는 여러가지 실행된다.
	s4 = s2;
	s5 = "My String"; // copy assignment ( = 연산자 오버로딩해서 구현)
	s1.copyAssignment("My Data");

	// s5 = std::move(s1);	// move assignment

	// std::string str3 = "홍길동";
	// str = "MyName : " + str3;

	s5 = s1 + "홍길동";
	
	s5 = "홍길동" + s1;

	cout << s5 << "\n 다른 객체의 정보 : " << s1;


}