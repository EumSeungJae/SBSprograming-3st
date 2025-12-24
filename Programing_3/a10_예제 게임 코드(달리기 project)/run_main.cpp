#include "ConsoleRenderer.h"
#include "run_GameObject.h"

int main() {
	ConsoleRenderer console;

	run_GameObject* goArray[8];



	goArray[0] = new run_GameObject;
	goArray[1] = new run_GameObject(80, 6, "cpp run project", 5);
	goArray[2] = new run_GameObject(80, 6, "speedy", 1);
	goArray[3] = new jump_gameObject(80, 6, "jump", 3, 2);
	goArray[4] = new jump_gameObject(80, 8, "rabit", 2, 2);
	goArray[5] = new jump_gameObject(80, 8, "tutle", 4, 2);
	goArray[6] = new dash_gameObject(80, 10, "dash", 3, 2);
	//goArray[7] = new burrow_gameObject(80, 10, "burrow", 3, 2);

	while (true) {
		// 플레이어 입력 player -> update

		// gameobject -> Update

		//for (int i = 0; i < 5; i++) {
		//	goArray[i]->update();
		//}
		for (const auto& go : goArray) {
			go->update();
		}

		// Rendering
		console.Clear();

		//for (int i = 0; i < 5; i++) {
		//	goArray[i]->draw(console);
		//}
		for (const auto& go : goArray) {
			go->draw(console);
		}
		// Flip
		console.Flipping();


		// 고정 대기 시간 Frame Per Second
		Sleep(17); // 60프레임. => 16


	}
	delete[] goArray;
}
