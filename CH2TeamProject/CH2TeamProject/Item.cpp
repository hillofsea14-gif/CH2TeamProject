#include <iostream>
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
        std::cout << name << "이(가) 없습니다." << std::endl;
        return false;
    }

    character.SetHP(character.GetHP() + healAmount);

    std::cout << name << " 사용!" << std::endl;
    std::cout << healAmount << "만큼 회복했습니다." << std::endl;
    std::cout << "현재 HP : " << character.GetHP() << std::endl;

    count--;
    return true;
}
