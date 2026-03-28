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

    virtual void Draw() const = 0;

    // Getter()
    std::string GetName() const;

    int GetCurrentHP() const;

    int GetMaxHP() const;

    int GetDef() const;

    int GetAtt() const;

    int GetSpd() const;

    int GetDam() const;

    int GetLvl() const;

    float GetGivingExp() const;   // [한길] 시스템 변경으로 자료형 변경.

    int GetGivingGold() const;   // [한길] 기빙골드 겟터 추가.

    // Setter()
    void SetName(std::string InName);

    void SetCurrentHP(int InCurrentHP);

    void SetMaxHP(int InMaxHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);



private:
    std::string name;
    int CurrentHP;
    int MaxHP;
    int Def;
    int Att;
    int Spd;
    int Dam;
    int Lvl;
    float GivingExp;   // [한길] 시스템 변경으로 자료형 변경.
    int GivingGold;   // [한길] 몬스터 사냥시 플레이어가 얻는 골드.
};

