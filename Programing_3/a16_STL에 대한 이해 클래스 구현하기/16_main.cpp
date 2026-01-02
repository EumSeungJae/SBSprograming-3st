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
//std::vector
//std::algorithm

using namespace std;

class Monster {
private:
	int _hp;
	int _atk;
	string _name;
public:
	int GetStrength() const { return _hp + _atk; }

	bool operator>(const Monster& other) {
		// 나의_hp (Monster)other.hp
		return (_hp + _atk) > (other._hp + other._atk);
	}
	void Attack(Player player) {
		player.Damage(_atk);
	}

	Monster(int hp, int atk, string name) : _hp(hp), _atk(atk), _name(name) {}
	Monster() : Monster{ 100,10,"나나시" } {}

	void Damage(int amount) { _hp -= amount; }

	bool isDeath() { return _hp <= 0; }

};

struct CompareStrength {
	bool operator()(const Monster* a, const Monster* b)
	{
		return a->GetStrength() > b->GetStrength();
	}
};

// Room 게임 등장하는 게임 요소를 인카운트 시키는 객체이다.
class Room {
	// Monster* unique_ptr
private:
	vector<Monster*> AvailableMonsters;	// 랜덤한 몬스터들이 배정되어 있다.
	vector<Monster*> settingsMonster;	// 약한 몬스터가 0번 배열에 저장이 되어 있다.
	// 자료구조이름 <몬스터>
public:
	void Initialize(const vector<Monster*>& copyMonsters) {
		AvailableMonsters = copyMonsters;
	}

	// 몬스터 들의 강함 순위를 정해서 약한 몬스터가 앞에서 등장하게 구현하고 싶다.
	// (순서를 재정렬하고 싶다)

	void SetOrder()  // 알고리즘 라이브러리를 가져와서 코드를 실행하겠다.
	{
		settingsMonster = AvailableMonsters;
		sort(AvailableMonsters.begin(), AvailableMonsters.end(), CompareStrength());
		// begin 시작 과 end 끝
	}

	int RoomCount() { return settingsMonster.size(); }

	Monster* Encount(int roomIndex) { return settingsMonster[roomIndex]; }

	// 0 ~ 10	[5	end]		rbegin 역행시작 rend 역행끝
	// 정렬을 해주지 않았다.
	// 어떤 내용을 기준으로 정렬을 할것인가?
	// 

	// int arr[] {1,2,3};	 arr(주소) + 1
};

// player.		battleManager
class Player {
private:
	int _hp;
	int _atk;
public:
	Player(int hp, int atk) : _hp(hp), _atk(atk) {}
	Player() : Player{ 1000,100 } {}

	void Attack(Monster* mon) {
		mon->Damage(_atk);
	}

	void Damage(int amount) { _hp -= amount; }
	bool isDeath() { return _hp <= 0; }
};

class BattleManager {
private:
	void Battle(Player& player, Monster* mon) {
		while (true) {
			// 턴
			int playerIndex = 0;
			cout << "player 턴" << endl;
			// 내가먼저
			cin >> playerIndex;
			player.Attack(mon);

			// 니가먼저
			mon->Attack(player);

			if (player.isDeath() || mon->isDeath()) {
				break;
			}
		}
		if(player.isDeath()){}
		if(mon->isDeath()){}
		
		// 몬스터가 죽었으면 다음 전투를 진행
		// 플레이어가 죽었으면 종료
	}

public:

	void PlayRoom(Player& player, Room room)
	{
		int battleCount = room.RoomCount();

		for (int i = 0; i < battleCount; i++) {
			// 전투

			// 첫번째 방에 있는 오브젝트[몬스터]와 조우했다.
			Monster* mon = room.Encount(i);

			Battle(player, mon);

			// 플레이어가 사망했으면?
			if (player.isDeath()) {
				break;
			}
		}

	}
};

int main() {
	cout << "16강 STL 예제" << endl;

	Room room;
	vector<Monster*> copyMonsters;
	copyMonsters.push_back(new Monster(70, 7, "슬라임C")); // 77
	copyMonsters.push_back(new Monster(50, 5, "슬라임A")); // 55
	copyMonsters.push_back(new Monster(80, 8, "슬라임D")); // 88
	copyMonsters.push_back(new Monster(60, 6, "슬라임B")); // 66

	room.Initialize(copyMonsters);
	room.SetOrder();



	// room에 있는 몬스터와 만났다.

}