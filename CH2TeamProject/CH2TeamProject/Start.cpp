// Start.cpp

#include <windows.h>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>

#include "Start.h"
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
#include "Battle.h"
#include "Render.h"
#pragma comment(lib, "winmm.lib")

int GameStart()
{
    ::PlaySoundA("opening.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    std::string name;
    int menu = 0;

    LogManager::PrintStartScreen();
    std::cin >> name;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    LogManager::PrintMessage("환영합니다, " + name + "님!");

    ::PlaySoundA("mainmenu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

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
            if (player.GetLevel() < 5 && player.GetCurrentHP() > 0) // [승민] 3.30 전투 입장시 플레이어 레벨에 따라 등장하는 몬스터가 달라지도록 수정.
            {
                ::PlaySoundA("dungeon1.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                Slime slime(player.GetLevel());
                if (Battle(player, slime) == 444) return 0;  //[한길] 3.31 사망시 바로 사망창으로 이동하게 추가함.
                if (player.GetCurrentHP() > 0)
                {
                    Wolf wolf(player.GetLevel()); // [승민] 몬스터 생성시 플레이어 레벨을 매개변수로 받아야함.[한길] 3.30 캐릭터에 GetLevel 추가
                    if (Battle(player, wolf) == 444) return 0;
                }
            }
            else if (player.GetLevel() >= 5 && player.GetLevel() < 10 && player.GetCurrentHP() > 0)
            {
                ::PlaySoundA("dungeon2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                WildCat wildcat(player.GetLevel());
                if (Battle(player, wildcat) == 444) return 0;
                if (player.GetCurrentHP() > 0)
                {
                    Gorani gorani(player.GetLevel());
                    if (Battle(player, gorani) == 444) return 0;
                }
            }
            else if (player.GetLevel() >= 10 && player.GetLevel() < 15 && player.GetCurrentHP() > 0)
            {
                ::PlaySoundA("dungeon3.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                Spider spider(player.GetLevel());
                if (Battle(player, spider) == 444) return 0;
                if (player.GetCurrentHP() > 0)
                {
                    Snake snake(player.GetLevel());
                    if (Battle(player, snake) == 444) return 0;
                }
            }
            else if (player.GetLevel() >= 15 && player.GetLevel() < 20 && player.GetCurrentHP() > 0)
            {
                ::PlaySoundA("dungeon4.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                BigNuguri bignuguri(player.GetLevel());
                if (Battle(player, bignuguri) == 444) return 0;
            }
            else if (player.GetLevel() >= 20 && player.GetCurrentHP() > 0)
            {
                ::PlaySoundA("dungeon5.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                WildBoar wildboar(player.GetLevel());
                if (Battle(player, wildboar) == 444) return 0;
                if (player.GetCurrentHP() > 0)
                {
                    Bear bear(player.GetLevel());
                    if (Battle(player, bear) == 444) return 0;
                }
                if (player.GetCurrentHP() > 0)
                {
                    Tiger tiger(player.GetLevel());
                    if (Battle(player, tiger) == 444) return 0;

                    // [한길] 3.31 전투 후 플레이어가 살아있다면 (보스 승리)
                    if (player.GetCurrentHP() > 0)
                    {
                        LogManager::ClearScreen();
                        //LogManager::PrintMessage("축하합니다! 전설의 타이거를 물리쳤습니다!");
                        return 777; // 엔딩 코드 반환
                    }
                }
            }
            LogManager::ClearScreen();
            ::PlaySoundA("mainmenu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            break;
        }

        case 2:
        {
            ::PlaySoundA("backpack.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            LogManager::DrawMainUI();
            LogManager::ClearBattleLogArea();
            LogManager::ClearInfoArea();
            LogManager::ClearRightPanel();

            //LogManager::Print
            LogManager::PrintBattleLog("[ 인벤토리 ]", 0);
            LogManager::PrintBattleLog("사용할 아이템 번호를", 1);
            LogManager::PrintBattleLog("선택하세요.", 2);

            LogManager::GoToXY(61, 1);
            std::cout << "[ 인벤토리 화면 ]";

            player.ShowItems();

            LogManager::GoToXY(29, 24);
            std::cout << "골드 : " << player.GetGold();

            LogManager::PrintInfoBox("선택 : ", 7);

            int choice = 0;
            if (!ReadIntAt(9, 25, choice))
            {
                LogManager::ClearBattleLogArea();
                LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
                WaitForNext();
                break;
            }

            if (choice == 0)
            {
                LogManager::ClearBattleLogArea();
                ::PlaySoundA("mainmenu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                break;
            }

            int beforeHP = player.GetCurrentHP();
            bool usedItem = player.UseItem(choice - 1);
            int afterHP = player.GetCurrentHP();
            int healed = afterHP - beforeHP;

            LogManager::DrawBattleUI();
            LogManager::ClearBattleLogArea();

            LogManager::PrintPlayerInfo(   // [한길]3.30 레벨 출력 추가.
                player.GetName(),
                player.GetLevel(),
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
            ::PlaySoundA("mainmenu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            break;
        }

        case 3:
        {
            ::PlaySoundA("shop.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

            LogManager::DrawMainUI();
            LogManager::ClearBattleLogArea();
            LogManager::ClearInfoArea();
            LogManager::ClearRightPanel();

            LogManager::GoToXY(63, 1);
            std::cout << "[ 상점 화면 ]";
            LogManager::PrintBattleLog("원하는 기능을 선택하세요.", 1);

            //LogManager::PrintMessage("상점에 입장합니다");  //[한길] 3.30 수정.[성윤] 불필요한 메시지 제거.
            Shop::ShowShopTopMenu(player);

            LogManager::PrintInfoBox("선택 : ", 7);


            //std::cin >> input;
            int input = 0;
            if (!ReadIntAt(9, 25, input))  // [성윤] 선택창 이거로 해야 원하는데 옆에 나와용
            {
                LogManager::ClearBattleLogArea();
                LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
                WaitForNext();
                break;
            }

            if (input == 1) // 구매 모드
            {
                LogManager::ClearInfoArea();
                Shop::ShowShopBuyMenu(player);
                LogManager::PrintInfoBox("선택 : ", 7);

                int choice = 0;
                if (!ReadIntAt(9, 25, choice))  // [성윤] 선택창 이거로 해야 원하는데 옆에 나와용
                {
                    LogManager::ClearBattleLogArea();
                    LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
                    WaitForNext();
                    break;
                }
                //int choice;
                //std::cin >> choice;

                // 구매 가능한 옵션(1, 2)인 경우에만 실행
                if (choice == 1 || choice == 2)
                {
                    bool success = Shop::BuyItem(player, choice);

                    LogManager::ClearBattleLogArea();
                    if (!success)
                    {
                        LogManager::PrintBattleLog("구매할 수 없습니다.", 0);
                    }
                    else if (choice == 1)
                    {
                        LogManager::ClearInfoArea();            // [한길] 3.31 아이템 판매시 소지개수도 갱신되게함. 
                        Shop::ShowShopSellMenu(player);         // 하지만 밑에 잔액부분이 잘림. but 골드게 표시되기 때문에 상관없어보임
                        LogManager::PrintBattleLog("미니 포션을 구매했습니다!", 0);
                    }
                    else if (choice == 2)
                    {
                        LogManager::ClearInfoArea(); 
                        Shop::ShowShopSellMenu(player);
                        LogManager::PrintBattleLog("대형 포션을 구매했습니다!", 0);
                    }

                    WaitForNext();
                }
                else if (choice == 0)
                {
                    LogManager::ClearBattleLogArea();
                    LogManager::PrintBattleLog("구매를 취소했습니다.", 0);
                    WaitForNext();
                }
                else
                {
                    LogManager::PrintMessage("잘못된 선택입니다.");
                }
            }
            else if (input == 2) // 판매 모드
            {
                LogManager::ClearInfoArea();
                Shop::ShowShopSellMenu(player);
                LogManager::PrintInfoBox("선택 : ", 7);

                int choice = 0;
                //int choice;
                //std::cin >> choice;
                // 판매 가능한 옵션인 경우에만 실행
                if (!ReadIntAt(9, 25, choice))  // [성윤] 선택창 이거로 해야 원하는데 옆에 나와용
                {
                    LogManager::ClearBattleLogArea();
                    LogManager::PrintBattleLog("숫자를 입력해주세요.", 0);
                    WaitForNext();
                    break;
                }

                if (choice == 1 || choice == 2)
                {
                    bool success = Shop::SellItem(player, choice);
                    LogManager::ClearBattleLogArea();
                    if (!success)
                    {
                        LogManager::PrintBattleLog("판매할 수 없습니다.", 0);
                    }
                    else if (choice == 1)
                    {
                        LogManager::ClearInfoArea();            // [한길] 3.31 아이템 판매시 소지개수도 갱신되게함. 
                        Shop::ShowShopSellMenu(player);         // 하지만 밑에 잔액부분이 잘림. but 골드게 표시되기 때문에 상관없어보임
                        LogManager::PrintBattleLog("미니 포션을 판매했습니다!", 0);
                    }
                    else if (choice == 2)
                    {
                        LogManager::ClearInfoArea();
                        Shop::ShowShopSellMenu(player);
                        LogManager::PrintBattleLog("대형 포션을 판매했습니다!", 0);
                    }

                    WaitForNext();
                }
                else
                {
                    LogManager::PrintMessage("잘못된 선택입니다.");
                }

            }
            else if (input == 0)
            {
                LogManager::PrintMessage("상점을 나갑니다.");
            }
            else
            {
                LogManager::PrintMessage("잘못된 입력입니다.");
            }
            ::PlaySoundA("mainmenu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            break;
        }

        case 4:
        {
            LogManager::PrintMessage("게임을 종료합니다.");
            return 1;          //[한길] 3.31 4번 눌러 게임 종료시 다른 화면 출력 위해 1 반환하게함.
        }

        default:
        {
            LogManager::DrawMainUI();
            LogManager::ClearBattleLogArea();
            LogManager::PrintBattleLog("잘못된 입력입니다.", 0);
            WaitForNext();
            break;
        }
        }
    }

    return 0;
}
