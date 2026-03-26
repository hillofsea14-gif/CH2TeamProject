#pragma once

#include <string>

class Character;

class Item
{
public:
    Item(std::string InName, int InHealAmount, int InCount);

    std::string GetName() const;
    int GetHealAmount() const;
    int GetCount() const;

    void AddCount(int amount);
    bool Use(Character& character);

private:
    std::string name;
    int healAmount;
    int count;
};
