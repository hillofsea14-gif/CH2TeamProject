// Battle.cpp

#include "Battle.h"

bool IsPlayerFast(Character& character, Monster& monster)
{
    return character.GetSpd() >= monster.GetSpd();    // [한길] 3.30 속도가 같으면 플레이어 선공되게 =>로 수정.
}

void PAttack(Character& character, Monster& monster)
{
    character.attack(character, monster);
}

void MAttack(Character& character, Monster& monster)
{
    monster.attack(character, monster);
}

void Battle(Character& character, Monster& monster)
{
    bool isplayerfast = IsPlayerFast(character, monster);

    RefreshBattleScreen(character, monster);

    LogManager::PrintBattleLog("[" + monster.GetName() + "] 와(과) 조우했습니다!", 0);
    LogManager::PrintBattleLog("전투에 돌입합니다!!!", 1);
    WaitForNext();

    if (!isplayerfast)
    {
        MAttack(character, monster);
        RefreshBattleScreen(character, monster);

        LogManager::ClearBattleLogArea();
        LogManager::PrintBattleLog("상대가 더 빠릅니다.", 0);
        LogManager::PrintBattleLog(monster.GetName() + "이(가) 먼저 공격합니다!!", 1);
        LogManager::PrintBattleLog(
            std::to_string(monster.GetDam()) + "만큼의 피해를 주었습니다.", 2
        );

        if (character.GetCurrentHP() <= 0)
        {
            LogManager::PrintBattleLog("캐릭터가 사망하였습니다.", 3);
            WaitForNext();
            return;
        }
        WaitForNext();
    }

    while (character.GetCurrentHP() > 0 && monster.GetCurrentHP() > 0)
    {
        RefreshBattleScreen(character, monster);

        int choice = 0;
        if (!ReadIntAt(10, 27, choice))
        {
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
            WaitForNext();
            continue;
        }

        if (choice == 1)
        {
            PAttack(character, monster);
            RefreshBattleScreen(character, monster);

            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog(
                character.GetName() + "이(가) " + monster.GetName() + "을(를) 공격합니다!!", 0
            );
            LogManager::PrintBattleLog(
                std::to_string(character.GetDam()) + "만큼의 피해를 주었습니다.", 1
            );

            if (monster.GetCurrentHP() <= 0)
            {
                character.EarnExp(monster.GetGivingExp());
                character.EarnGold(monster);

                LogManager::PrintBattleLog("몬스터가 사망하였습니다.", 2);
                LogManager::PrintBattleLog("전투 승리!!", 3);
                LogManager::PrintBattleLog(
                    std::to_string(monster.GetGivingExp()) + " EXP를 획득했습니다.", 4
                );
                LogManager::PrintBattleLog(
                    std::to_string(monster.GetGivingGold()) + " G를 획득했습니다.", 5
                );

                WaitForNext();
                break;
            }
            WaitForNext();
        }
        else if (choice == 2)
        {
            int beforeHP = character.GetCurrentHP();
            bool usedItem = OpenItemMenu(character);
            int afterHP = character.GetCurrentHP();
            int healed = afterHP - beforeHP;

            RefreshBattleScreen(character, monster);
            LogManager::ClearBattleLogArea();

            if (!usedItem)
            {
                LogManager::PrintBattleLog("아이템을 사용하지 않았습니다.", 0);
                WaitForNext();
                continue;
            }

            if (healed > 0)
            {
                LogManager::PrintBattleLog("포션을 사용했습니다!", 0);
                LogManager::PrintBattleLog(
                    character.GetName() + "의 체력이 " + std::to_string(healed) + " 회복되었습니다.", 1
                );
                LogManager::PrintBattleLog(
                    "현재 HP : " + std::to_string(character.GetCurrentHP()) + "/" +
                    std::to_string(character.GetMaxHP()), 2
                );
            }
            else
            {
                LogManager::PrintBattleLog("포션을 사용했지만 회복되지 않았습니다.", 0);
            }

            WaitForNext();
        }
        else if (choice == 3)
        {
            RefreshBattleScreen(character, monster);
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("당신은 도망쳤습니다...", 0);
            WaitForNext();
            break;
        }
        else
        {
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("잘못된 입력입니다.", 0);
            WaitForNext();
            continue;
        }

        if (monster.GetCurrentHP() > 0)
        {
            MAttack(character, monster);
            RefreshBattleScreen(character, monster);

            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog(
                monster.GetName() + "이(가) " + character.GetName() + "을(를) 공격합니다!!", 0
            );
            LogManager::PrintBattleLog(
                std::to_string(monster.GetDam()) + "만큼의 피해를 주었습니다.", 1
            );

            if (character.GetCurrentHP() <= 0)
            {
                LogManager::PrintBattleLog("캐릭터가 사망하였습니다.", 2);
                WaitForNext();
                break;
            }
            WaitForNext();
        }
    }
}
