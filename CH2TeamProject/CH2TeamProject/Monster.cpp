// Monster.cpp

#include <iostream>

#include "Monster.h"
#include "Character.h"


Monster::Monster(std::string InName)
    : name(InName), HP(100), Def(10), Att(20), Spd(7), Dam(0) // Lvl(1), GivingExp(50)
                                                               //[한길] 레벨, 주는 경험치 추가 
{

}

void Monster::attack(Character& character, Monster& monster)
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << name << "이(가) " << character.GetName() << "을(를) 공격합니다!!" << std::endl;
    Dam = Att - character.GetDef();                       // [한길] 일단 공격력에서 방어력을 뺀 값으로 딜이 들어가게 함.
    if (Dam < 0)
    {
        Dam = 0;
    }                        //  [성윤] 방어력이 공격력보다 높을 때, 데미지가 음수가 되는 것을 방지.
    std::cout << Dam << "만큼의 피해를 주었습니다." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;

    character.takeDamage(monster);
}

void Monster::takeDamage(Character& character)
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "몬스터 " << name << "이(가) " << character.GetName()
        << "에게 " << character.GetDam() << "만큼의 피해를 입었습니다." << std::endl;
    HP -= character.GetDam();
    if (HP < 0)                                      // [한길] 체력이 0보다 아래로 떨어지는 것 방지.
    {
        HP = 0;
    }
    std::cout << "현재 " << name << "의 남은 체력은 " << HP << " 입니다." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
}

void Monster::printcurrentstatus() const
{
    std::cout << "-----------Current Status: -----------\n";
    std::cout << "몬스터 " << name << "의 현재 상태입니다." << std::endl;
    std::cout << "HP : " << HP << std::endl;
    std::cout << "Def : " << Def << std::endl;
    std::cout << "Att : " << Att << std::endl;
    std::cout << "Spd : " << Spd << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
}


// Getter()
std::string Monster::GetName() const
{
    return name;
}

int Monster::GetHP() const
{
    return HP;
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

/* [한길] 레벨, 주는 경험치 Getter 추가. 레벨 시스템 변경으로 주석처리
int Monster::GetLvl() const
{
    return Lvl;
}

int Monster::GetGivingExp() const
{
    return GivingExp;
*/

// Setter()
void Monster::SetName(std::string InName)
{
    name = InName;
    return;
}

void Monster::SetHP(int InHP)
{
    HP = InHP;
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
