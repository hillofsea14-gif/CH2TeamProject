// Character.h

#pragma once

#include <string>
#include "Monster.h"
#include "LevelComponent.h"
#include "Item.h"
#include <vector>


class Character
{
public:
    Character(std::string InName);
    ~Character();

    void attack(Character& character, Monster& monster);

    void takeDamage(Monster& monster);

    void printcurrentstatus() const;   // [한길] 멤버변수로 LevelComp가 생겨서 매개변수 삭제함.

    void EarnExp(float Amount);     // [한길] Amount의 인자값이 될 몬스터의 givingExp를 float으로 수정함.

    // Getter()
    std::string GetName() const;

    int GetHP() const;

    int GetDef() const;

    int GetAtt() const;

    int GetSpd() const;

    int GetDam() const;


    // Setter()
    void SetName(std::string InName);

    void SetHP(int InHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);

    void AddItem(const Item& item);

    void ShowItems() const;

    bool UseItem(int index);



private:
    std::vector<Item> items;
    std::string name;
    int HP;
    int Def;
    int Att;
    int Spd;
    int Dam;
    LevelComponent* LevelComp;
};

