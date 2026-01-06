// 접근 지정자.
	// 생성 ~ 소멸자
	// 상속 - 구성
	// 스마트 포인터

// STL c++ 개발자(게임) - STL 잘 아시나요?
// Standard Template Library (신뢰할 수 있는 라이브러리)
// 자료구조 - 알고리즘

// 컨테이너 알고리즘(Algorithm) 반복자(iterator)


#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <Windows.h>

#include "Player.h"
#include "Monster.h"
//std::vector
//std::algorithm

using namespace std;



struct CompareStrength {
	bool operator()(const Monster* a, const Monster* b)
	{
		return a->GetStrength() > b->GetStrength();
	}
};

// 반복이 계속되는 것을 피하고 싶다.
// 조금더 최적화된 코드를 작성하고 싶다.
// 어떤 기준으로 판단할 것인가?

// Room 게임 등장하는 게임 요소를 인카운트 시키는 객체이다.
class Room {
	// Monster* unique_ptr
private:
	vector<GameObject*> roomObjects;

	vector<Monster*> AvailableMonsters;	// 랜덤한 몬스터들이 배정되어 있다.
	vector<Monster*> settingsMonster;	// 약한 몬스터가 0번 배열에 저장이 되어 있다.
	// 자료구조이름 <몬스터>

	vector<TreasureObject*> roomTeasures; // 방에서 생성될 수 있는 보물 정보
public:
	void Initialize(const vector<Monster*>& copyMonsters) {
		AvailableMonsters = copyMonsters;
	}

	// 몬스터 들의 강함 순위를 정해서 약한 몬스터가 앞에서 등장하게 구현하고 싶다.
	// (순서를 재정렬하고 싶다)

	void SetTreasureRoom(TreasureObject* tr) {
		roomTeasures.push_back(tr);
	}

	void SetOrder()  // 알고리즘 라이브러리를 가져와서 코드를 실행하겠다.
	{
		settingsMonster = AvailableMonsters;
		sort(AvailableMonsters.begin(), AvailableMonsters.end(), CompareStrength());
		// begin 시작 과 end 끝

		for (const auto& go : settingsMonster)
		{
			roomObjects.push_back(go);

		}
	}

	int RoomCount() { return roomObjects.size(); }

	GameObject* Encount(int roomIndex) { return roomObjects[roomIndex]; }

	// 0 ~ 10	[5	end]		rbegin 역행시작 rend 역행끝
	// 정렬을 해주지 않았다.
	// 어떤 내용을 기준으로 정렬을 할것인가?
	// 

	// int arr[] {1,2,3};	 arr(주소) + 1
};

// player.		battleManager

class BattleManager {
private:
	void RoomEvent(GameObject* gameobject) {

	}

	// GameObject -> virtual void RoomEntryEvent();
	// 몬스터방 -> 전투, 보물상자 -> 상자획득, 함정 -> 함정
	void Battle(Player* player, BattleObject* other) {
		// 턴
		while (true) {
			int playerIndex = 0;
			cout << "player 턴" << endl;
			// 내가먼저
			cin >> playerIndex;
			player->Attack(other);

			cout << "적의 턴!" << endl;
			// 니가먼저
			cout << "적의 턴 진행중... " << endl;
			Sleep(1000);
			other->Attack(player);
			cout << "모든 적의 턴 끝날때 대기중..." << endl;

			if (player->IsDeath() || other->IsDeath()) {
				break;
			}
		}
	}

	void GetTreasure(TreasureObject* tr)
	{
		// 플레이어가 getTreasure 실제로 get 했다.
		//player->GetItem(item)
		tr->GetTreasure();
		//Item* tempItem = new Item(tr->money, tr->contents);
		//player->GetItem(TempItem);

	}

public:

	void PlayRoom(Player* player, Room room)
	{
		int battleCount = room.RoomCount();

		for (int i = 0; i < battleCount; i++) {
			// 전투

			// 첫번째 방에 있는 오브젝트[몬스터]와 조우했다.

			cout << i + 1 << "번째 방에 진입했습니다." << endl;

			// i번방에 있는 요소가 몬스터 이외의 정보도 가질 수 있으면 좋겠어
			GameObject* obj = room.Encount(i);

			if (BattleObject* mon = dynamic_cast<BattleObject*>(obj))
				/*obj 만약에 BattleObject* 타입이면*/
			{
				// Battle함수를 실행할거에요
				// 타입을 변경하는 문법 Type Casting
				Battle(player, mon);
			}
			else if (TreasureObject* tr = dynamic_cast<TreasureObject*>(obj)) {
				GetTreasure(tr);
			}

			// obj -> Type : 3가지 행동을 할 수 있다.
			// 배틀 : Battle();
			// 보물 : GetTreasusre();
			// 휴식 : Rest();



			// 플레이어가 사망했으면?
			if (player->IsDeath())
			{
				cout << i + 1 << "번째 방에서 플레이거 사망했습니다." << endl;
				return;
			}
			system("cls");
		}

	}
};

int main() {
	cout << "16강 STL 예제" << endl;

	Room room0;
	vector<Monster*> copyMonsters;

	copyMonsters.push_back(new Monster(3, RoomObjectType::BATTLE, 700, 7, "슬라임C")); // 77
	copyMonsters.push_back(new Monster(1, RoomObjectType::BATTLE, 500, 5, "슬라임A")); // 55
	copyMonsters.push_back(new Monster(4, RoomObjectType::BATTLE, 800, 8, "슬라임D")); // 88
	copyMonsters.push_back(new Monster(2, RoomObjectType::BATTLE, 600, 6, "슬라임B")); // 66

	room0.SetTreasureRoom(new TreasureObject(10001, RoomObjectType::TREASURE, 500, "금화상자"));

	room0.Initialize(copyMonsters);
	room0.SetOrder();

	//
	//Stage 클래스. 클래스 vector Room 타입을 가지고 있고,
	//클래스가 모든 Room을 클리어 하면 해당 Stage가 끝났다.

	vector<Room> Stage;

	Player* player = new Player();
	// room에 있는 몬스터와 만났다.
	BattleManager _bm;

	Room room1;
	Room room2;
	Room room3;

	Stage.push_back(room0);
	Stage.push_back(room1);
	Stage.push_back(room2);
	Stage.push_back(room3);
	//---------------set data-----------------//

	int stageIndex = 0;

	while (true) {
		// 입력

		//갱신
		
		//Type에 

		_bm.PlayRoom(player, Stage[stageIndex]);
		stageIndex++;

		//렌터링
	}


}

