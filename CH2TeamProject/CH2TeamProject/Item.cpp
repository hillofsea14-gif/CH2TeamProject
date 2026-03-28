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
