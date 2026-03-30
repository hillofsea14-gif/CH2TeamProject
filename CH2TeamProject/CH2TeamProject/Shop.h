// Shop.h


#pragma once
#include <memory>
#include <string>
#include "Character.h"
#include "Item.h"

class Shop
{
public:
    // 정보창에 구매, 판매 선택.          [한길] 3.30 추가.
    static void ShowShopTopMenu();

    // 상점 메뉴를 보여주는 함수
    static void ShowShopBuyMenu();

    static void ShowShopSellMenu();

    // 아이템 구매 로직 (성공/실패 여부 리턴)
    static bool BuyItem(Character& player, int choice);

    static bool SellItem(Character& player, int choice);  // [한길] 3.30 아이템 판매 추가
};
