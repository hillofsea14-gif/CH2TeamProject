// Shop.h


#pragma once
#include <memory>
#include <string>
#include "Character.h"
#include "Item.h"

class Shop
{
public:
    // 상점 메뉴를 보여주는 함수
    static void ShowShopMenu();

    // 아이템 구매 로직 (성공/실패 여부 리턴)
    static bool BuyItem(Character& player, int choice);
};
