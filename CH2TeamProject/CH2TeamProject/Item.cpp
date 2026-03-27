#include <iostream>
#include "Item.h"
#include "Character.h"
#include "Logmanager.h"


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
        LogManager::PrintMessage(name + "이(가) 없습니다.");
        return false;
    }

    character.SetCurrentHP(character.GetCurrentHP() + healAmount);

    LogManager::PrintMessage(name + " 사용!");
    LogManager::PrintMessage(std::to_string(healAmount) + "만큼 회복했습니다.");
    LogManager::PrintMessage("현재 HP : " + std::to_string(character.GetCurrentHP())
        + "/" + std::to_string(character.GetMaxHP()));
    count--;
    return true;
}
