// Item.cpp

#include "Item.h"
#include "Character.h"

Item::Item(std::string InName, int InHealAmount, int InCount)
    : name(InName), healAmount(InHealAmount), count(InCount)
{
}

std::string Item::GetName() const
{
    return name;
}

int Item::GetHealAmount() const
{
    return healAmount;
}

int Item::GetCount() const
{
    return count;
}

void Item::AddCount(int amount)
{
    count += amount;
}

bool Item::Use(Character& character)
{
    if (count <= 0)
    {
        return false;
    }

    character.SetCurrentHP(character.GetCurrentHP() + healAmount);

    count--;
    return true;
}

MiniPotion::MiniPotion(int InCount)  // [한길] 추가.
    : Item("미니 포션", 100, InCount)  // [한길] 3.30 아이템 이름으로 찾기 기능 추가하며 이름 수정.
{

}

BigPotion::BigPotion(int InCount)
    : Item("대형 포션", 200, InCount)
{

}
