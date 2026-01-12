#include "Render.h"
#include <iostream>

void Render::Draw(const Player& p, const std::vector<Monster>& monsters)
{
    system("cls");
    for (int i = 0; i < p.GetHP(); i++) std::cout << "●";
    for (int i = p.GetHP(); i < p.GetMaxHP(); i++) std::cout << "○";
    std::cout << "\n";

    for (const auto& m : monsters)
        if (!m.IsDead())
            std::cout << "M@" << m.GetX() << " ";

    std::cout << "\nPlayer [" << p.GetStepChar() << "] X:" << p.GetX() << " Y:" << p.GetY() << "\n";
    std::cout << "x:공격  c:점프  q:종료\n";
}
