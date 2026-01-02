#include "ConsoleRenderer.h"
#include "run_GameObject.h"

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

int main() {
	ConsoleRenderer console;

	// 1. 프로젝트 내부에 있는 파일을 읽어오세요.
	string filepath = "C:\\Users\\user\\Desktop\\programing\\SBSprograming-3st\\Programing_3\\a10_예제 게임 코드(달리기 project)\\run_object.json";

	std::ifstream ifs(filepath);

	// 2. 파일 읽기
	rapidjson::IStreamWrapper isw(ifs);

	Document doc;
	doc.ParseStream(isw);

	std::vector<run_GameObject*> runObject;

	// 3. 타입 변환(Parse)
	if (doc.IsArray()) {
		for (int i = 0; i < doc.Size(); i++) {
			const Value& obj = doc[i];

			if (obj.IsObject()) {	// json에서 "{ }" 묶여있나?

				// 조건 1.x 좌표
				if (obj.HasMember("x") && obj["x"].IsInt() &&
					obj.HasMember("y") && obj["y"].IsInt() &&
					obj.HasMember("shape") && obj["shape"].IsString() &&
					obj.HasMember("speed") && obj["speed"].IsInt()&&
					obj.HasMember("jumpPower") && obj["jumpPower"].IsInt()&&
					obj.HasMember("burrowDepth") && obj["burrowDepth"].IsInt())
				{
					run_GameObject* runInstance;
					if (obj["jumpPower"].GetInt() == 0 && 
						obj["burrowDepth"].GetInt() == 0) 
					{
						runInstance = new run_GameObject(
						obj["x"].GetInt(), obj["y"].GetInt(),
						obj["shape"].GetString(), obj["speed"].GetInt());
					}
					else if (obj["jumpPower"].GetInt() > 0) 
					{
						runInstance = new jump_gameObject(
							obj["x"].GetInt(), obj["y"].GetInt(),
							obj["shape"].GetString(), obj["speed"].GetInt(),
							obj["jumpPower"].GetInt());
					}
					else if (obj["burrowDepth"].GetInt() > 0) {
						runInstance = new burrow_gameObject(
							obj["x"].GetInt(), obj["y"].GetInt(),
							obj["shape"].GetString(), obj["speed"].GetInt(),
							obj["burrowDepth"].GetInt());
					}
					// 만약에 runInstance의 enum타입이 일반 타입이면 run_GameObject
					// enum 타입이 jump 타입이면 new jump_gameObject(80,6,"jump",1,2)

					runObject.push_back(runInstance);
				}
			}
		}
	}

	run_GameObject* goArray[8];

	goArray[0] = new run_GameObject;
	goArray[1] = new run_GameObject(80, 6, "cpp run project", 5);
	goArray[2] = new run_GameObject(80, 6, "speedy", 1);
	goArray[3] = new jump_gameObject(80, 6, "jump", 3, 2);
	goArray[4] = new jump_gameObject(80, 8, "rabit", 2, 2);
	goArray[5] = new jump_gameObject(80, 8, "tutle", 4, 2);
	goArray[6] = new dash_gameObject(80, 10, "dash", 3, 2);
	goArray[7] = new burrow_gameObject(80, 10, "burrow", 3, 2);

	while (true) {
		// 플레이어 입력 player -> update

		// gameobject -> Update

		//for (int i = 0; i < 5; i++) {
		//	goArray[i]->update();
		//}
		for (const auto& go : runObject) {
			go->update();
		}

		// Rendering
		console.Clear();

		//for (int i = 0; i < 5; i++) {
		//	goArray[i]->draw(console);
		//}
		for (const auto& go : runObject) {
			go->draw(console);
		}
		// Flip
		console.Flipping();


		// 고정 대기 시간 Frame Per Second
		Sleep(17); // 60프레임. => 16


	}
	delete[] goArray;
}
