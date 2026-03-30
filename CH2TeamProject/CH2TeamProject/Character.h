// Character.h

#pragma once

#include <string>
#include "Monster.h"
#include "LevelComponent.h"
#include "Item.h"
#include <vector>
#include <memory> // [한길] shared_ptr 공구통.


class Character
{
public:
    Character(std::string InName);
    ~Character();

    void attack(Character& character, Monster& monster);

    void takeDamage(Monster& monster);

    // void printcurrentstatus() const; [한길] 해당 함수가 삭제된것 같아 주석처리함.

    void EarnExp(float Amount);

    void EarnGold(Monster& monster);

    // Getter()
    std::string GetName() const;

    int GetCurrentHP() const;

    int GetMaxHP() const;

    int GetDef() const;

    int GetAtt() const;

    int GetSpd() const;

    int GetDam() const;

    int GetGold() const;

    float GetCurrentExp() const;

    float GetMaxExp() const;

    const std::vector<std::shared_ptr<Item>>& GetItems() const; // [한길] 아이템 출력 위한 Getter 추가.


    // Setter()
    void SetName(std::string InName);

    void SetCurrentHP(int InCurrentHP);

    void SetMaxHP(int InMaxHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);

    void AddItem(std::shared_ptr<Item> newItem); // [한길] 변경

    void ShowItems() const;

    bool UseItem(int index);

    void SetGold(int InGold);   // [한길] 상점 위해 추가.



private:
    std::vector<std::shared_ptr<Item>> items;   // [한길] 추가 여러가지 포션 클래스를 받아주기 위해 포인터를 모으는 백터를 만듦.
    std::string name;
    int CurrentHP;
    int MaxHP;
    int Def;
    int Att;
    int Spd;
    int Dam;
    int Gold;
    LevelComponent* LevelComp;
};

