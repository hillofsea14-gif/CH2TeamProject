// Monster.h


#pragma once

#include <string>
// [한길] #include "Character.h" 순환참조문제가 생김. 따라서 전방선언해줌.

class Character;

class Monster
{
public:
    Monster(std::string InName);

    void attack(Character& character, Monster& monster);

    void takeDamage(Character& character);

    void printcurrentstatus() const;


    // Getter()
    std::string GetName() const;

    int GetHP() const;

    int GetDef() const;

    int GetAtt() const;

    int GetSpd() const;

    int GetDam() const;

    //[한길] 레벨, 주는 경험치 Getter 추가. 레벨 시스템 변경으로 주석처리
    //int GetLvl() const;

    //int GetGivingExp() const;

    // Setter()
    void SetName(std::string InName);

    void SetHP(int InHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);



private:
    std::string name;
    int HP;
    int Def;
    int Att;
    int Spd;
    int Dam;
    //[한길] 레벨, 몬스터가 주는 경험치 추가. 레벨 시스템 변경으로 주석처리
    //int Lvl;
    //int GivingExp;
};

