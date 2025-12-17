#define _CRT_SECURE_NO_WARNINGS
#include "Mystring.h"

Mystring::Mystring() : str(nullptr)
{
	str = new char[1];
	*str = '\n';
}

Mystring::Mystring(const char* source) : str(nullptr)
{
	str = new char[std::strlen(source) + 1]; 
	// source의 길이 만큼 char 길이를 메모리에 저장하고 싶다.
	strcpy(str, source);
}

Mystring::Mystring(const Mystring& other)
{
	str = new char[std::strlen(other.str) + 1];
	strcpy(str, other.str);
}

Mystring::Mystring(Mystring&& rhs) noexcept
{
	str = rhs.str;
	rhs.str = nullptr;
}

Mystring::~Mystring()
{
	delete[] str;
}

Mystring Mystring::operator=(const Mystring& other)
{
	if (this == &other)
		return *this;

	delete[] str;
	str = new char[std::strlen(other.str) + 1];
	std::strcpy(str, other.str);

	return *this;
}
Mystring Mystring::operator=(Mystring&& rhs) noexcept
{
	if (this == &rhs)
		return *this;

	delete[] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);

	return *this;
}

Mystring Mystring::copyAssignment(const Mystring& other)
{
	if (this == &other)
		return *this;

	delete[] str;
	str = new char[std::strlen(other.str) + 1];
	std::strcpy(str, other.str);

	return *this;
	
}

ostream& operator<<(ostream& os, const Mystring& obj)
{
	os << obj.str;

	return os;
}

Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
	char* buffer = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
	// this.str 길이= this.str 길이 + oher.str 길이 + 널문자(1)
	strcpy(buffer, lhs.str);		// buffer[시작 ~ A]
	strcat(buffer, rhs.str);	// buffer[A ~ other길이]

	Mystring temp(buffer);	// const char* 매개변수로 하는 생성자 호출
	delete[] buffer;		// 사용을 다한 buffer 공간을 메모리 해제

	return temp;
}
