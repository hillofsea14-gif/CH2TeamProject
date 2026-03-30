// Render.cpp

#include "Render.h"

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
        character.GetLevel(),   //[한길] 레벨 겟터 추가
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



bool ReadIntAt(int x, int y, int& outValue)
{
    LogManager::GoToXY(x, y);

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
        character.GetLevel(),  //[한길] 3.30 레벨 겟터 추가
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
