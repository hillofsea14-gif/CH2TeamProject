// Shop.cpp


#include "Shop.h"
#include "LogManager.h" 
#include <iostream>

void Shop::ShowShopMenu()
{
    // 정보창에 상점 물품 목록 출력
    LogManager::PrintInfoBox("========= 중간 상점 =========", 0);
    LogManager::PrintInfoBox("1. 미니 포션 (50G)", 1);
    LogManager::PrintInfoBox("2. 대형 포션 (100G)", 2);
    LogManager::PrintInfoBox("0. 나가기", 3);
    for (int i = 4; i < 8; i++)
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
