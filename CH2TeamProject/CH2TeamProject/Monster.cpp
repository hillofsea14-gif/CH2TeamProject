// Monster.cpp

#include <iostream>

#include "Monster.h"
#include "Character.h"
#include "LogManager.h"



Monster::Monster(std::string InName)
    : name(InName), CurrentHP(100), MaxHP(100), Def(10), Att(20), Spd(7), Dam(0), Lvl(1), GivingExp(50.f), GivingGold(5)
{

}

void Monster::attack(Character& character, Monster& monster)
{
    Dam = Att - character.GetDef();                       // [한길] 일단 공격력에서 방어력을 뺀 값으로 딜이 들어가게 함.
    if (Dam < 0)
    {
        Dam = 0;
    }
    character.takeDamage(monster);
}

void Monster::takeDamage(Character& character)
{
    SetCurrentHP(CurrentHP - character.GetDam());
}

// Getter()
std::string Monster::GetName() const
{
    return name;
}

int Monster::GetCurrentHP() const
{
    return CurrentHP;
}

int Monster::GetMaxHP() const
{
    return MaxHP;
}

int Monster::GetDef() const
{
    return Def;
}

int Monster::GetAtt() const
{
    return Att;
}

int Monster::GetSpd() const
{
    return Spd;
}

int Monster::GetDam() const
{
    return Dam;
}

int Monster::GetLvl() const
{
    return Lvl;
}

float Monster::GetGivingExp() const  // [한길] 시스템 변경으로 int에서 float으로 변경.
{
    return GivingExp;
}

int Monster::GetGivingGold() const
{
    return GivingGold;
}

// Setter()
void Monster::SetName(std::string InName)
{
    name = InName;
    return;
}

void Monster::SetCurrentHP(int InHP)
{
    CurrentHP = InHP;

    if (CurrentHP > MaxHP)
    {
        CurrentHP = MaxHP;
    }

    if (CurrentHP < 0)
    {
        CurrentHP = 0;
    }
}

void Monster::SetMaxHP(int InMaxHP)
{
    MaxHP = InMaxHP;

    if (MaxHP < 1)
    {
        MaxHP = 1;
    }

    if (CurrentHP > MaxHP)
    {
        CurrentHP = MaxHP;
    }
}

void Monster::SetDef(int InDef)
{
    Def = InDef;
}

void Monster::SetAtt(int InAtt)
{
    Att = InAtt;
}

void Monster::SetSpd(int InSpd)
{
    Spd = InSpd;
}
