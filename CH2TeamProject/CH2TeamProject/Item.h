// Item.h

#pragma once

#include <string>

class Character;

class Item
{
public:
    Item(std::string InName, int InHealAmount, int InCount);

    virtual ~Item() {}    // [한길] 스마트 포인트 사용으로 자식 클래스 메모리 해제 위함.

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

class MiniPotion : public Item   // [한길] 자식클래스 추가.
{
public:
    MiniPotion(int InCount);

};


class BigPotion : public Item
{
public:
    BigPotion(int InCount);

};
