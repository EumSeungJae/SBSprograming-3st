#include "01_namespace.h"

void A::ShowPlayer() {
	std::cout << "A의 플레이어 입니다." << std::endl;
}

void B::ShowPlayer() {
	std::cout << "B의 플레이어 입니다." << std::endl;
}

void ShowPlayer()
{
	std::cout << "그냥 플레이어 입니다." << std::endl;
}
