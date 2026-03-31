#include <iostream>
#include <string>
#include <windows.h>
#include "LogManager.h"
#include "Item.h"

void LogManager::PrintLine()
{
    std::cout << "========================================" << std::endl;
}

void LogManager::PrintTitle(const std::string& title)
{
    PrintLine();
    std::cout << " " << title << std::endl;
    PrintLine();
}

void LogManager::PrintMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

void LogManager::PrintEncounter(const std::string& monsterName)
{
    PrintLine();
    std::cout << "몬스터 [" << monsterName << "] 와(과) 조우했습니다!" << std::endl;
    PrintLine();
}

void LogManager::PrintBattleStart()
{
    std::cout << "전투에 돌입합니다!!!" << std::endl;
}

void LogManager::PrintPlayerTurnMenu()
{
    std::cout << "\n당신의 행동을 선택하세요." << std::endl;
    std::cout << "1. 공격" << std::endl;
    std::cout << "2. 가방" << std::endl;
    std::cout << "3. 도망간다" << std::endl;
    std::cout << "선택: ";

}

void LogManager::PrintRunAway()
{
    std::cout << "당신은 도망쳤습니다..." << std::endl;
}

void LogManager::PrintInvalidInput()
{
    std::cout << "잘못된 입력입니다." << std::endl;
}

void LogManager::PrintEnemyTurn()
{
    std::cout << "상대가 공격합니다." << std::endl;
}

void LogManager::PrintMainMenu()
{
    ClearScreen();

    const int width = 60;
    const int height = 15;

    // 윗줄 / 아랫줄
    for (int x = 0; x < width; x++)
    {
        GoToXY(x, 0);
        std::cout << "=";
        GoToXY(x, height - 1);
        std::cout << "=";
    }

    // 양옆줄
    for (int y = 0; y < height; y++)
    {
        GoToXY(0, y);
        std::cout << "|";
        GoToXY(width - 1, y);
        std::cout << "|";
    }

    // 제목
    GoToXY(22, 1);
    std::cout << "[ 메인 메뉴 ]";

    // 메뉴 목록
    GoToXY(4, 4);
    std::cout << "1. 전투 입장";

    GoToXY(4, 5);
    std::cout << "2. 인벤토리";  //[한길] 수정.

    GoToXY(4, 6);
    std::cout << "3. 상점";  //[한길] 수정. 수정. 3.30

    GoToXY(4, 7);
    std::cout << "4. 게임 종료";

    // 입력칸 구분선
    for (int x = 1; x < width - 1; x++)
    {
        GoToXY(x, 11);
        std::cout << "-";
    }

    GoToXY(4, 12);
    std::cout << "선택 : ";
}

void LogManager::PrintStartScreen()
{
    std::cout << "\n\n\n\n\n\n";


    std::cout << "                                                ==========================\n\n";
    std::cout << "                                                         집 으 로\n\n";
    std::cout << "                                                ==========================\n\n";
    std::cout << "\n\n";

    std::cout << "                                                ==========================\n\n";
    std::cout << "                                                     당신의 이름은...?\n\n";
    std::cout << "                                                ==========================\n\n\n";
    std::cout << "\n";
    std::cout << "                                                >> ";
}

void LogManager::PrintCenter(const std::string& text)
{
    const int width = 100;
    int padding = (width - static_cast<int>(text.size())) / 2;

    if (padding < 0)
        padding = 0;

    std::cout << std::string(padding, ' ') << text << std::endl;
}

void LogManager::PrintCenterInputPrompt()
{
    const int width = 100;
    std::string prompt = ">> ";
    int padding = (width - static_cast<int>(prompt.size())) / 2;

    if (padding < 0)
        padding = 0;

    std::cout << std::string(padding, ' ') << prompt;
}

void LogManager::GoToXY(int x, int y)
{
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void LogManager::SetConsoleSize(int Width, int Height)
{
    HANDLE HOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (HOut == INVALID_HANDLE_VALUE) return;

    COORD BufferSize = { static_cast<SHORT>(Width), static_cast<SHORT>(Height) };

    SMALL_RECT WindowSize = { 0, 0, static_cast<SHORT>(Width - 1), static_cast<SHORT>(Height - 1) };

    SMALL_RECT MinWindow = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(HOut, TRUE, &MinWindow);

    SetConsoleScreenBufferSize(HOut, BufferSize);
    SetConsoleWindowInfo(HOut, TRUE, &WindowSize);
}

void LogManager::ClearScreen()
{
    system("cls");
}

void LogManager::DrawBattleUI()
{
    ClearScreen();

    const int width = 100;
    const int height = 30;

    // 바깥 테두리
    for (int x = 0; x < width; x++)
    {
        GoToXY(x, 0);
        std::cout << "=";
        GoToXY(x, height - 1);
        std::cout << "=";
    }

    for (int y = 0; y < height; y++)
    {
        GoToXY(0, y);
        std::cout << "|";
        GoToXY(width - 1, y);
        std::cout << "|";
    }

    // 왼쪽 / 오른쪽 구분선
    for (int y = 1; y < height - 1; y++)
    {
        GoToXY(41, y);
        std::cout << "|";
    }

    // 왼쪽 위 / 아래 구분선
    for (int x = 1; x < 41; x++)
    {
        GoToXY(x, 15);
        std::cout << "-";
    }

    // 제목
    GoToXY(2, 1);
    std::cout << "[ 배틀 로그 ]";

    GoToXY(2, 16);
    std::cout << "[ 정보 ]";

    GoToXY(59, 1);
    std::cout << "[ 몬스터 / 전투 화면 ]";
}

void LogManager::DrawMainUI()
{
    ClearScreen();

    const int width = 100;
    const int height = 30;

    // 바깥 테두리
    for (int x = 0; x < width; x++)
    {
        GoToXY(x, 0);
        std::cout << "=";
        GoToXY(x, height - 1);
        std::cout << "=";
    }

    for (int y = 0; y < height; y++)
    {
        GoToXY(0, y);
        std::cout << "|";
        GoToXY(width - 1, y);
        std::cout << "|";
    }

    // 왼쪽 / 오른쪽 구분선
    for (int y = 1; y < height - 1; y++)
    {
        GoToXY(41, y);
        std::cout << "|";
    }

    // 왼쪽 위 / 아래 구분선
    for (int x = 1; x < 41; x++)
    {
        GoToXY(x, 15);
        std::cout << "-";
    }

    // 제목
    GoToXY(2, 1);
    std::cout << "[ 배틀 로그 ]";

    GoToXY(2, 16);
    std::cout << "[ 정보 ]";
}

void LogManager::PrintBattleLog(const std::string& message, int line)
{
    std::string output = message;

    if (output.size() > 36)
    {
        output = output.substr(0, 36);
    }

    GoToXY(2, 3 + line);
    std::cout << "                                      ";
    GoToXY(2, 3 + line);
    std::cout << output;
    GoToXY(41, 3 + line);
    std::cout << "|";
}

void LogManager::PrintInfoBox(const std::string& message, int line)
{
    std::string output = message;

    if (output.size() > 36)
    {
        output = output.substr(0, 36);
    }

    GoToXY(2, 18 + line);
    std::cout << "                                      ";
    GoToXY(2, 18 + line);
    std::cout << output;
    GoToXY(41, 18 + line);
    std::cout << "|";
}

void LogManager::PrintMonsterBox(const std::string& message, int line)
{
    GoToXY(46, 3 + line);
    std::cout << "                                                ";
    GoToXY(46, 3 + line);
    std::cout << message;
}

void LogManager::PrintPlayerInfo(const std::string& name, int level, int hp, int maxHP, int att, int def, int spd, int gold,
    float currentExp, float maxExp, const std::vector<std::shared_ptr<Item>>& items)
{
    ClearInfoArea();

    PrintInfoBox("이름 : " + name, 0);          // [한길] 3.30레벨 출력 추가.
    PrintInfoBox("HP : " + std::to_string(hp) + " / " + std::to_string(maxHP), 1);

    GoToXY(2, 20);
    std::cout << "Level : " << level;

    GoToXY(24, 20);
    std::cout << "Exp : " << (int)currentExp << " / " << (int)maxExp;

    GoToXY(2, 21);
    std::cout << "공격력 : " << att;

    GoToXY(24, 21);
    std::cout << "방어력 : " << def;

    GoToXY(2, 22);
    std::cout << "속도 : " << spd;

    GoToXY(2, 23);
    std::cout << "골드 : " << gold;

    if (items.size() > 0)
    {
        GoToXY(2, 24);
        std::cout << "미니 포션 : " << items[0]->GetCount() << "개";
    }

    if (items.size() > 1)
    {
        GoToXY(24, 24);
        std::cout << "대형 포션 : " << items[1]->GetCount() << "개";
    }
    /*int line = 7;          // [한길] 6번 라인부터 아이템 목록 출력. - [성윤] 아이템 목록이 7번 라인부터 출력되도록 수정.
    for (const auto& item : items)
    {
        if (line > 8) // 정보창 크기 제한이 있다면 방어 코드
        {
            break;
        }
        PrintInfoBox(item->GetName() + " : " + std::to_string(item->GetCount()) + "개", line++);
    }*/
}

void LogManager::PrintMonsterInfo(const std::string& name, int hp, int maxHP, int att, int def, int spd)
{
    PrintMonsterBox("이름 : " + name, 0);
    PrintMonsterBox("HP : " + std::to_string(hp) + " / " + std::to_string(maxHP), 1);
    PrintMonsterBox("공격력 : " + std::to_string(att), 2);
    PrintMonsterBox("방어력 : " + std::to_string(def), 3);
    PrintMonsterBox("속도 : " + std::to_string(spd), 4);
}

void LogManager::PrintBattleMenuUI()
{
    GoToXY(2, 26);
    std::cout << "1. 공격   2. 가방   3. 도망가기          ";

    GoToXY(2, 27);
    std::cout << "선택 :                    ";
}

void LogManager::ClearRightPanel()
{
    for (int y = 2; y < 28; y++)
    {
        GoToXY(44, y);
        std::cout << "                                                      ";
    }
}

void LogManager::DrawMainMenuInRightPanel()
{
    ClearRightPanel();

    GoToXY(64, 3);
    std::cout << "[ 메인 메뉴 ]";

    GoToXY(48, 7);
    std::cout << "1. 전투 입장";

    GoToXY(48, 9);
    std::cout << "2. 인벤토리";  // [한길] 수정.

    GoToXY(48, 11);
    std::cout << "3. 상점";  // [한길] 수정. 수정. 3.30

    GoToXY(48, 13);
    std::cout << "4. 게임 종료";

    GoToXY(48, 20);
    std::cout << "선택 : ";
}

void LogManager::DrawPlayerStatusInRightPanel(const std::string& name, int hp, int maxHP, int att, int def, int spd, int gold)
{
    ClearRightPanel();

    GoToXY(53, 3);
    std::cout << "[ 플레이어 스텟 ]";

    GoToXY(48, 7);
    std::cout << "이름 : " << name;

    GoToXY(48, 11);
    std::cout << "HP : " << hp << " / " << maxHP;

    GoToXY(48, 13);
    std::cout << "공격력 : " << att;

    GoToXY(48, 15);
    std::cout << "방어력 : " << def;

    GoToXY(48, 17);
    std::cout << "속도 : " << spd;

    GoToXY(48, 19);
    std::cout << "Gold : " << gold << " G";

    GoToXY(48, 23);
    std::cout << "엔터를 누르면 돌아갑니다...";
}

void LogManager::ClearBattleLogArea()
{
    for (int y = 3; y <= 14; y++)
    {
        GoToXY(2, y);
        std::cout << "                                      ";
        GoToXY(41, y);
        std::cout << "|";
    }
}

void LogManager::ClearInfoArea()
{
    for (int y = 18; y <= 25; y++)
    {
        GoToXY(2, y);
        std::cout << "                                      ";
        GoToXY(41, y);
        std::cout << "|";
    }
}
