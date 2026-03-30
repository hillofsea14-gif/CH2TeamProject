// Shop.cpp


#include "Shop.h"
#include "LogManager.h" 
#include <iostream>

void Shop::ShowShopTopMenu()
{
    // 정보창에 구매, 판매 선택.          [한길] 3.30 추가.
    LogManager::PrintInfoBox("========= 중간 상점 =========", 0);
    LogManager::PrintInfoBox("1. 구매", 1);
    LogManager::PrintInfoBox("2. 판매", 2);
    LogManager::PrintInfoBox("0. 나가기", 3);
    for (int i = 4; i < 10; i++)
    {
        LogManager::PrintInfoBox(" ", i); // 빈칸 채우기
    }
}

void Shop::ShowShopBuyMenu()
{
    // 정보창에 상점 물품 목록 출력
    LogManager::PrintInfoBox("========= 중간 상점 =========", 0);
    LogManager::PrintInfoBox("1. 미니 포션 구매(50G)", 1);
    LogManager::PrintInfoBox("2. 대형 포션 구매(100G)", 2);
    LogManager::PrintInfoBox("0. 나가기", 3);
    for (int i = 4; i < 10; i++)
    {
        LogManager::PrintInfoBox(" ", i); // 빈칸 채우기
    }
}

void Shop::ShowShopSellMenu()
{
    // 정보창에 상점 물품 목록 출력
    LogManager::PrintInfoBox("========= 중간 상점 =========", 0);
    LogManager::PrintInfoBox("1. 미니 포션 판매(30G)", 1);
    LogManager::PrintInfoBox("2. 대형 포션 판매(60G)", 2);
    LogManager::PrintInfoBox("0. 나가기", 3);
    for (int i = 4; i < 10; i++)
    {
        LogManager::PrintInfoBox(" ", i); // 빈칸 채우기
    }
}

bool Shop::BuyItem(Character& player, int choice)
{
    int price = 0;
    std::string itemName = "";
    std::shared_ptr<Item> newItem = nullptr;

    // 선택에 따른 아이템 설정
    if (choice == 1)
    {
        price = 50;
        itemName = "미니 포션";
        newItem = std::make_shared<MiniPotion>(1);
    }
    else if (choice == 2)
    {
        price = 100;
        itemName = "대형 포션";
        newItem = std::make_shared<BigPotion>(1);
    }
    else
    {
        return false; // 잘못된 선택이니 나가기
    }

    // 골드 체크 및 구매 처리
    if (player.GetGold() >= price)
    {
        player.SetGold(player.GetGold() - price);
        player.AddItem(newItem);

        // 결과 알림
        LogManager::PrintMessage(itemName + "을(를) 구매했습니다!");
        LogManager::PrintMessage("잔액: " + std::to_string(player.GetGold()) + "G");
        return true;
    }
    else
    {
        // 골드 부족 알림
        LogManager::PrintMessage("골드가 부족합니다! (필요: " + std::to_string(price) + "G)");
        return false;
    }
}

bool Shop::SellItem(Character& player, int choice)
{
    int price = 0;
    std::string targetName = "";

    // 선택에 따른 아이템 설정
    if (choice == 1)
    {
        price = 30;
        targetName = "미니 포션";
    }
    else if (choice == 2)
    {
        price = 60;
        targetName = "대형 포션";
    }
    else
    {
        return false; // 잘못된 선택이니 나가기
    }

    // 플레이어 인벤토리에서 실제 아이템을 가져옴
    std::shared_ptr<Item> itemInItems = player.FindItemByName(targetName);

    // 아이템이 실제로 있고, 개수가 0보다 큰지 확인
    if (itemInItems && itemInItems->GetCount() > 0)
    {
        // 판매 처리: 골드 증가
        player.SetGold(player.GetGold() + price);

        // 개수 감소
        itemInItems->AddCount(-1);

        LogManager::PrintMessage(targetName + "을(를) 판매했습니다!");

        // 만약 개수가 0이 되었다면 인벤토리 목록에서 삭제
        /*
        if (itemInItems->GetCount() <= 0) {
            player.RemoveItem(itemInItems);
            LogManager::PrintMessage(targetName + "의 수량이 모두 소진되어 제거되었습니다.");
        }
        */

        LogManager::PrintMessage("잔액: " + std::to_string(player.GetGold()) + "G");
        return true;
    }
    else
    {
        LogManager::PrintMessage("판매할 " + targetName + "이(가) 인벤토리에 없습니다.");
        return false;
    }
}
