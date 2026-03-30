// Main.cpp

#include <iostream>
#include <string>
#include <limits>

#include "Character.h"
#include "Monster.h"
#include "LevelComponent.h"
#include "Slime.h" // [승민] 몬스터 헤더파일 추가```
#include "Snake.h"
#include "Bear.h"
#include "Spider.h"
#include "Wolf.h"
#include "WildCat.h"
#include "Gorani.h"
#include "BigNuguri.h"
#include "WildBoar.h"
#include "Tiger.h" // [승민]```
#include "LogManager.h"
#include "Shop.h"

void WaitForNext()
{
    LogManager::GoToXY(2, 28);
    std::cout << "엔터를 누르면 계속합니다...           ";
    std::cin.get();
    LogManager::GoToXY(2, 28);
    std::cout << "                                  ";
}

void ShowMainScreen(Character& character)
{
    LogManager::DrawBattleUI();

    LogManager::PrintBattleLog("집으로 돌아가기 위한 여정", 0);
    LogManager::PrintBattleLog("행동을 선택하세요.", 1);

    LogManager::PrintPlayerInfo(
        character.GetName(),
        character.GetCurrentHP(),
        character.GetMaxHP(),
        character.GetAtt(),
        character.GetDef(),
        character.GetSpd(),
        character.GetGold(),
        character.GetCurrentExp(),
        character.GetMaxExp(),
        character.GetItems()  // [한길] 이 함수가 출력되는 곳에 모두 GetItem() 함수 추가.
    );
    LogManager::DrawMainMenuInRightPanel();
}

bool IsPlayerFast(Character& character, Monster& monster)
{
    return character.GetSpd() > monster.GetSpd();
}

void PAttack(Character& character, Monster& monster)
{
    character.attack(character, monster);
}

void MAttack(Character& character, Monster& monster)
{
    monster.attack(character, monster);
}

bool ReadIntAt(int x, int y, int& outValue)
{
    if (!(std::cin >> outValue))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

bool OpenItemMenu(Character& character)
{
    character.ShowItems();

    int choice = 0;
    if (!ReadIntAt(10, 27, choice))
    {
        LogManager::ClearBattleLogArea();
        LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
        return false;
    }

    if (choice == 0)
    {
        return false;
    }

    return character.UseItem(choice - 1);
}

void RefreshBattleScreen(Character& character, Monster& monster)
{
    LogManager::DrawBattleUI();
    LogManager::PrintPlayerInfo(
        character.GetName(),
        character.GetCurrentHP(),
        character.GetMaxHP(),
        character.GetAtt(),
        character.GetDef(),
        character.GetSpd(),
        character.GetGold(),
        character.GetCurrentExp(),
        character.GetMaxExp(),
        character.GetItems()  // [한길] 이 함수가 출력되는 곳에 모두 GetItem() 함수 추가.
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

int main()
{
    std::string name;
    int menu = 0;

    LevelComponent* MyLevel = new LevelComponent(); // [승민] 플레이어 레벨 객체 생성
    LogManager::PrintStartScreen();
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    LogManager::PrintMessage("환영합니다, " + name + "님!");

    Character player(name);
    auto InitializeMiniPotion = std::make_shared<MiniPotion>(3);     // [한길] 미니포션 3개 가진 객체를 생성하고 포인터를 반환함.
    auto InitializeBigPotion = std::make_shared<BigPotion>(0);   // [한길] 빅포션 초기화.
    player.AddItem(InitializeMiniPotion);                      // [한길] 추가.
    player.AddItem(InitializeBigPotion);                      // [한길] 일단 추가. 목록에 0개라고 뜸.

    while (true)
    {
        ShowMainScreen(player);

        if (!ReadIntAt(54, 20, menu))
        {
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
            continue;
        }

        switch (menu)
        {
        case 1:
        {

           
            LogManager::PrintMessage("전투에 입장합니다.");

            srand(time(NULL));
            Wolf monster(MyLevel->GetCurrentLevel()); // [승민] 몬스터 생성시 플레이어 레벨을 매개변수로 받아야함.
            Battle(player, monster);
            LogManager::ClearScreen();
            break;
        }

        case 2:
        {
            LogManager::DrawBattleUI();
            LogManager::ClearBattleLogArea();
            LogManager::ClearInfoArea();

            LogManager::PrintBattleLog("[ 인벤토리 ]", 0);
            LogManager::PrintBattleLog("사용할 아이템 번호를", 1);
            LogManager::PrintBattleLog("선택하세요.", 2);

            player.ShowItems();

            LogManager::PrintInfoBox("선택 : ", 7);

            int choice = 0;
            LogManager::GoToXY(9, 25);
            if (!(std::cin >> choice))
            {
                LogManager::ClearBattleLogArea();
                LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
                WaitForNext();
                break;
            }

            if (choice == 0)
            {
                LogManager::ClearBattleLogArea();
                break;
            }

            int beforeHP = player.GetCurrentHP();
            bool usedItem = player.UseItem(choice - 1);
            int afterHP = player.GetCurrentHP();
            int healed = afterHP - beforeHP;

            LogManager::DrawBattleUI();
            LogManager::ClearBattleLogArea();

            LogManager::PrintPlayerInfo(
                player.GetName(),
                player.GetCurrentHP(),
                player.GetMaxHP(),
                player.GetAtt(),
                player.GetDef(),
                player.GetSpd(),
                player.GetGold(),
                player.GetCurrentExp(),
                player.GetMaxExp(),
                player.GetItems()
            );
            LogManager::DrawMainMenuInRightPanel();

            if (!usedItem)
            {
                LogManager::PrintBattleLog("아이템을 사용할 수", 0);
                LogManager::PrintBattleLog("없습니다.", 1);
                WaitForNext();
            }
            else if (healed > 0)
            {
                LogManager::PrintBattleLog("포션을 사용했습니다!", 0);
                LogManager::PrintBattleLog(
                    std::to_string(healed) + " 만큼 회복되었습니다.", 1
                );
                LogManager::PrintBattleLog(
                    "현재 HP : " + std::to_string(player.GetCurrentHP()) + " / " +
                    std::to_string(player.GetMaxHP()), 2
                );
                WaitForNext();
            }
            else
            {
                LogManager::PrintBattleLog("포션을 사용했지만", 0);
                LogManager::PrintBattleLog("회복되지 않았습니다.", 1);
                WaitForNext();
            }

            WaitForNext();
            break;
        }

        case 3:
        {
            LogManager::PrintMessage("상점에 입장합니다");
            Shop::ShowShopMenu();

            int input = 0;
            if (!(std::cin >> input))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                LogManager::PrintMessage("숫자를 입력해주세요.");
                WaitForNext();
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Shop::BuyItem(player, input);
            break;
        }

        case 4:
        {
            LogManager::DrawBattleUI();
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("미정입니다.", 0);
            WaitForNext();
            break;
        }

        case 5:
        {
            LogManager::PrintMessage("게임을 종료합니다.");
            return 0;
        }

        default:
        {
            LogManager::DrawBattleUI();
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("잘못된 입력입니다.", 0);
            WaitForNext();
            break;
        }
        }
    }
}
