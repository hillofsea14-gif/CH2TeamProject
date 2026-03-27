// Main.cpp

#include <iostream>
#include <string>

#include "Character.h"
#include "Monster.h"
#include "LevelComponent.h"
#include "Slime.h"
#include "LogManager.h"

bool IsPlayerFast(Character& character, Monster& monster)
{
    int A = character.GetSpd();
    int B = monster.GetSpd();

    return A > B;
}

void PAttack(Character& character, Monster& monster)
{
    character.attack(character, monster);
}

void MAttack(Character& character, Monster& monster)
{
    monster.attack(character, monster);
}

bool OpenItemMenu(Character& character)
{
    character.ShowItems();

    int choice;
    std::cin >> choice;

    if (choice == 0)
    {
        LogManager::PrintMessage("아이템창을 닫았습니다.");
        return false;
    }
    return character.UseItem(choice - 1);
}

void Battle(Character& character, Monster& monster)
{
    bool isplayerfast = IsPlayerFast(character, monster);

    LogManager::PrintEncounter(monster.GetName());
    LogManager::PrintBattleStart();

    character.printcurrentstatus();
    monster.printcurrentstatus();

    if (!isplayerfast)
    {
        LogManager::PrintMessage("상대가 더 빠릅니다. 공격권이 상대에게 넘어갑니다.");
        MAttack(character, monster);

        if (character.GetCurrentHP() <= 0)
        {
            LogManager::PrintMessage("캐릭터가 사망하였습니다.");
            return;
        }
    }

    while (character.GetCurrentHP() > 0 && monster.GetCurrentHP() > 0)
    {
        LogManager::PrintPlayerTurnMenu();

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            PAttack(character, monster);

            if (monster.GetCurrentHP() <= 0)
            {
                LogManager::PrintMessage("몬스터가 사망하였습니다.");
                LogManager::PrintMessage("전투 승리!!");
                character.EarnExp(monster.GetGivingExp());        // [한길] 경험치 함수 추가.
                break;
            }
        }
        else if (choice == 2)
        {
            bool usedItem = OpenItemMenu(character);

            if (!usedItem)
            {
                continue;
            }
        }
        else if (choice == 3)
        {
            LogManager::PrintRunAway();
            break;
        }
        else
        {
            LogManager::PrintInvalidInput();
            continue;
        }

        if (monster.GetCurrentHP() > 0)
        {
            LogManager::PrintEnemyTurn();
            MAttack(character, monster);
        }

        if (character.GetCurrentHP() <= 0)
        {
            LogManager::PrintMessage("캐릭터가 사망하였습니다.");
            break;
        }
    }
}

int main()
{
    std::string name;
    int menu = 0;

    LevelComponent* MyLevel = new LevelComponent();

    LogManager::PrintStartScreen();
    std::cin >> name;
    LogManager::PrintMessage("환영합니다, " + name + "님!");

    Character player(name);
    player.AddItem(Item("회복약", 50, 3));

    while (true)
    {
        LogManager::PrintMainMenu();
        std::cin >> menu;

        switch (menu)
        {
        case 1:
        {
            LogManager::PrintMessage("전투에 입장합니다.");

            Slime monster;
            Battle(player, monster);
            break;
        }

        case 2:
        {
            LogManager::PrintMessage("스텟창을 엽니다.");
            player.printcurrentstatus();
            break;
        }

        case 3:
        {
            LogManager::PrintMessage("미정입니다.");
            break;
        }

        case 4:
        {
            LogManager::PrintMessage("미정입니다.");
            break;
        }

        case 5:
        {
            LogManager::PrintMessage("게임을 종료합니다.");
            delete MyLevel;
            return 0;
        }

        default:
        {
            LogManager::PrintInvalidInput();
            break;
        }
        }
    }
}
