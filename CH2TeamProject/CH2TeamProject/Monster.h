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

    int GetLvl() const;

    float GetGivingExp() const;   // [한길] 시스템 변경으로 자료형 변경.

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
    int Lvl;
    float GivingExp;   // [한길] 시스템 변경으로 자료형 변경.
};

