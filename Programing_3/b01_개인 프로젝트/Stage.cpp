#include "Stage.h"
#include "Render.h"
#include "Battle.h"
#include <conio.h>

Stage::Stage()
{
    monsters.emplace_back(MonsterRank::WEAK, 5);
    monsters.emplace_back(MonsterRank::NORMAL, 10);
}

void Stage::Run()
{
    while (true)
    {
        player.Move();
        Render::Draw(player, monsters);

        if (_kbhit())
        {
            char k = _getch();
            if (k == 'q') break;
            if (k == 'c') player.Jump();
            if (k == 'x')
            {
                for (auto& m : monsters)
                {
                    if (!m.IsDead() && abs(m.GetX() - player.GetX()) <= player.GetStats().GetRange())
                    {
                        int dmg = Battle::CalcDamage(player, m);
                        m.SetHP(m.GetHP() - dmg);
                        if (m.IsDead()) player.GainExp(10);
                        break;
                    }
                }
            }
        }
    }
}
