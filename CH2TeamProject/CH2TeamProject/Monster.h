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

    int GetGivingExp() const;   // [한길] 시스템 변경으로 자료형 변경. [승민] 3.30 정수로 출력하기 위해서 int로 통일.

    int GetGivingGold() const;   // [한길] 기빙골드 겟터 추가.

    // Setter()
    void SetName(std::string InName);

    void SetCurrentHP(int InCurrentHP);

    void SetMaxHP(int InMaxHP);

    void SetDef(int InDef);

    void SetAtt(int InAtt);

    void SetSpd(int InSpd);

    void SetGivingGold(int InGivingGold); // 3.27 [승민] 몬스터 마다 골드량 변경을 위한 setter 함수 추가

    void SetGivingExp(int InGivingExp); // 3.27 [승민] 몬스터 마다 경험치량 변경을 위한 setter 함수 추가

    void SetLvl(int InLvl); // 3.27 [승민] 몬스터 마다 레벨설정을 위한 setter 함수 추가.   

private:
    std::string name;
    int CurrentHP;
    int MaxHP;
    int Def;
    int Att;
    int Spd;
    int Dam;
    int Lvl;
    int GivingExp;   // [한길] 시스템 변경으로 자료형 변경. [승민] 3.30 정수 출력하기 위해서 int로 통일.
    int GivingGold;   // [한길] 몬스터 사냥시 플레이어가 얻는 골드.
};

