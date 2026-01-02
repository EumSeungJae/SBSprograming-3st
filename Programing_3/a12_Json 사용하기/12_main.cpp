// cpp json 사용하기
// 객체를 표현하는 약속이다.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

class Run {
private:

public:
	int x;
	int y;
	string shape;
	int speed;
	Run(int x, int y, string shape, int speed);
};

int main() {
	cout << "12강 json 파일 읽기" << endl;

	// 1. 프로젝트 내부에 있는 파일을 읽어오세요.
	string filepath = "C:\\Users\\user\\Desktop\\programing\\SBSprograming-3st\\Programing_3\\a12_Json 사용하기\\run_object.json";

	std::ifstream ifs(filepath);

	// 2. 파일 읽기
	rapidjson::IStreamWrapper isw(ifs);

	Document doc;
	doc.ParseStream(isw);

	std::vector<Run> runObject;

	// 3. 타입 변환(Parse)
	if (doc.IsArray()) {
		for (int i = 0; i < doc.Size(); i++) {
			const Value& obj = doc[i];

			if (obj.IsObject()) {	// json에서 "{ }" 묶여있나?
				
				// 조건 1.x 좌표
				if (obj.HasMember("x") && obj["x"].IsInt() &&
					obj.HasMember("y") && obj["y"].IsInt() &&
					obj.HasMember("shape") && obj["shape"].IsString() &&
					obj.HasMember("speed") && obj["speed"].IsInt())
				{
					Run runInstance(
						obj["x"].GetInt(), obj["y"].GetInt(),
						obj["shape"].GetString(), obj["speed"].GetInt());

					runObject.push_back(runInstance);
				}
			}
		}
	}

	// 4. 예제 출력

	for (const auto& runInstance : runObject) {
		cout <<
			"x : " << runInstance.x <<
			"y : " << runInstance.y <<
			"shape : " << runInstance.shape <<
			"speed : " << runInstance.speed <<
			endl;
	}

}

Run::Run(int x, int y, string shape, int speed): 
	x(x),y(y),shape(shape),speed(speed){}
