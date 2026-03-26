// Character.h

#pragma once

#include <string>
#include "Monster.h"
#include "Item.h"
#include <vector>


class Character
{
public:
    Character(std::string InName);

    void attack(Character& character, Monster& monster);

    void takeDamage(Monster& monster);

    void printcurrentstatus() const;

    // [한길] 레벨업, 경험치 획득 함수 추가. 레벨 시스템 변경으로 주석처리
    //void LevelUp();

    //void EarnExp(Monster& monster);

    // Getter()
    std::string GetName() const;

    int GetHP() const;

    int GetDef() const;

    int GetAtt() const;

    int GetSpd() const;

    int GetDam() const;

    // [한길] 레벨, 경험치 Getter 추가. 레벨 시스템 변경으로 주석처리
    //int GetLvl() const;

    //int GetExp() const;

    // Setter()
    void SetName(std::string InName);

    void SetHP(int InHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);

    // [한길] 레벨, 경험치 Setter추가. 레벨 시스템 변경으로 주석처리
    //void SetLvl(int InLvl);

    //void SetExp(int InExp);

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
    // [한길] 캐릭터 레벨, 경험치, 최대경험치 추가. 레벨 시스템 변경으로 주석처리
    //int Lvl;
    //int Exp;
    //int MaxExp;
};

