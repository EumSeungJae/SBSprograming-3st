#include "Spawner.h"

// type(형) casting(변환)
// type : int, double, string, class, struct

class base
{
public:
	virtual void show() { cout << "base 입니다" << endl; }
};

class derived : public base
{
public:
	void show() { cout << "derived 입니다" << endl; }
};



int main() {
	cout << "1번 예제. 정수 - 실수 변환" << endl;

	double n1 = 10;
	n1 = (int)10.5;
	cout << n1 << endl;

	cout << "2번 예제. 객체의 타입을 변형해 보자" << endl;
	base* b1 = new base;
	base* b1ptr = new base;

	b1->show();
	derived* d1ptr = static_cast<derived*>(b1ptr);
	d1ptr->show();

	cout << "3번 예제. ( )형변환, 키워드를 통해서 형변환." << endl;
	cout << "static, dunamic, const_cast, reinterpret_cast" << endl;

	// 왜 cpp cast 여러 종류로 나누었을까?
	// 1. 객체, 다형성을 지닌 객체를 형변환하기 위한 키워드
	// 2. () : 3종류의 형변환을 할 수 있다. 
	// 어떤 형변환을 진행해서 문제가 생겼는지 판단하기 어려웠다.

	//static_cast<>();		컴파일 시점에 형변환 int -> double
	//dynamic_cast<>();		다형성을 지닌 객체를 형변환
	//const_cast<>();		const 성질을 지닌 변수를 const가 없는 형질을 변환해주는 변환
	//reinterpret_cast<>();	비트를 재해석하는 방식	<double>0000/0001

	cout << "4번 예제. enum과 형변환을 같이 쓰기" << endl;

	if (0 == static_cast<int>(MoveType::Normal)) {
		cout << "0으로 변환 되었습니다." << endl;
	}

	int input = 0;
	//cin >> input;
	MoveType m_type;

	m_type = static_cast<MoveType>(input);

	Run* runObject = nullptr;

	switch (m_type) {
	case MoveType::Normal:
		runObject = new Run(0, 0, "run", 0);
		break;
	case MoveType::Jump:
		runObject = new Jump(0, 0, "jump", 0, 0);
		break;
	case MoveType::Dash:
		runObject = new Dash(0, 0, "dash", 0, 0);
		break;
	}

	runObject->move();

	std::ifstream ifs("run_Object.json");
	IStreamWrapper isw(ifs);
	Document doc;
	doc.ParseStream(isw);

	auto objects = RunFactory::CreateFromValue(doc);

	Spawner mySpawner;
}