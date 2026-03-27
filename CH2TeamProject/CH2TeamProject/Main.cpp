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

    LogManager::DrawBattleUI();

    LogManager::PrintBattleLog("[" + monster.GetName() + "] 와(과) 조우했습니다!", 0);
    LogManager::PrintBattleLog("전투에 돌입합니다!!!", 1);

    LogManager::PrintPlayerInfo(
        character.GetName(),
        character.GetCurrentHP(),
        character.GetMaxHP(),
        character.GetAtt(),
        character.GetDef(),
        character.GetSpd()
    );

    LogManager::PrintMonsterInfo(
        monster.GetName(),
        monster.GetCurrentHP(),
        monster.GetMaxHP(),
        monster.GetAtt(),
        monster.GetDef(),
        monster.GetSpd()
    );

    monster.Draw();

    LogManager::PrintBattleMenuUI();

    if (!isplayerfast)
    {
        LogManager::PrintBattleLog("상대가 더 빠릅니다. 공격권이 상대에게 넘어갑니다.", 2);
        MAttack(character, monster);

        LogManager::PrintPlayerInfo(
            character.GetName(),
            character.GetCurrentHP(),
            character.GetMaxHP(),
            character.GetAtt(),
            character.GetDef(),
            character.GetSpd()
        );

        if (character.GetCurrentHP() <= 0)
        {
            LogManager::PrintBattleLog("캐릭터가 사망하였습니다.", 3);
            return;
        }
    }

    while (character.GetCurrentHP() > 0 && monster.GetCurrentHP() > 0)
    {
        LogManager::PrintBattleMenuUI();

        int choice;
        LogManager::GoToXY(10, 30);   // 선택 입력 위치
        std::cin >> choice;

        if (choice == 1)
        {
            PAttack(character, monster);

            LogManager::PrintBattleLog(
                character.GetName() + "이(가) " + monster.GetName() + "을(를) 공격합니다!!", 2
            );
            LogManager::PrintBattleLog(
                std::to_string(character.GetDam()) + "만큼의 피해를 주었습니다.", 3
            );


            LogManager::PrintMonsterInfo(
                monster.GetName(),
                monster.GetCurrentHP(),
                monster.GetMaxHP(),
                monster.GetAtt(),
                monster.GetDef(),
                monster.GetSpd()
            );

            if (monster.GetCurrentHP() <= 0)
            {
                LogManager::PrintBattleLog("몬스터가 사망하였습니다.", 4);
                LogManager::PrintBattleLog("전투 승리!!", 5);
                character.EarnExp(monster.GetGivingExp());
                LogManager::PrintMessage("몬스터가 사망하였습니다.");
                LogManager::PrintMessage("전투 승리!!");
                character.EarnExp(monster.GetGivingExp());        // [한길] 경험치 함수 추가.
                character.EarnGold(monster);  // [한길] 골드 획득 추가.
                break;
            }
        }
        else if (choice == 2)
        {
            bool usedItem = OpenItemMenu(character);

            LogManager::PrintPlayerInfo(
                character.GetName(),
                character.GetCurrentHP(),
                character.GetMaxHP(),
                character.GetAtt(),
                character.GetDef(),
                character.GetSpd()
            );

            if (!usedItem)
            {
                continue;
            }
        }
        else if (choice == 3)
        {
            LogManager::PrintBattleLog("당신은 도망쳤습니다...", 4);
            break;
        }
        else
        {
            LogManager::PrintBattleLog("잘못된 입력입니다.", 4);
            continue;
        }

        if (monster.GetCurrentHP() > 0)
        {
            LogManager::PrintBattleLog("상대가 공격합니다.", 5);
            MAttack(character, monster);
            LogManager::PrintBattleLog(
                monster.GetName() + "이(가) " + character.GetName() + "을(를) 공격합니다!!", 5
            );
            LogManager::PrintBattleLog(
                std::to_string(monster.GetDam()) + "만큼의 피해를 주었습니다.", 6
            );

            LogManager::PrintPlayerInfo(
                character.GetName(),
                character.GetCurrentHP(),
                character.GetMaxHP(),
                character.GetAtt(),
                character.GetDef(),
                character.GetSpd()
            );
        }

        if (character.GetCurrentHP() <= 0)
        {
            LogManager::PrintBattleLog("캐릭터가 사망하였습니다.", 6);
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
