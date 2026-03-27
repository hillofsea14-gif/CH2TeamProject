// Character.cpp

#include <iostream>
#include "Character.h"
#include "Item.h"

Character::Character(std::string InName)
    : name(InName), HP(100), Def(10), Att(20), Spd(5), Dam(0)
{
    // [상진] 객체 생성 시 레벨 컴포넌트 동적 할당
    LevelComp = new LevelComponent();
}

Character::~Character()
{
    if (LevelComp != nullptr)
    {
        //[상진] 소멸 시 메모리 해제
        delete LevelComp;
        LevelComp = nullptr;
        std::cout << "[시스템] Character 소멸: LevelComponont 메모리가 해제되었습니다." << std::endl;
    }
}


void Character::attack(Character& character, Monster& monster)
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "플레이어 " << name << "이(가) " << monster.GetName() << "을(를) 공격합니다!!" << std::endl;
    Dam = Att - monster.GetDef();                       // [한길] 일단 공격력에서 방어력을 뺀 값으로 딜이 들어가게 함.
    if (Dam < 0)
    {
        Dam = 0;              //  [성윤] 방어력이 공격력보다 높을 때, 데미지가 음수가 되는 것을 방지.
    }
    std::cout << Dam << "만큼의 피해를 주었습니다." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;

    monster.takeDamage(character);

}

void Character::takeDamage(Monster& monster)
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "플레이어 " << name << "이(가) " << monster.GetName()
        << "에게 " << monster.GetDam() << "만큼의 피해를 입었습니다." << std::endl;
    HP -= monster.GetDam();
    if (HP < 0)                                      // 체력이 0보다 아래로 떨어지는 것 방지.
    {
        HP = 0;
    }
    std::cout << "현재 플레이어 " << name << "의 남은 체력은 " << HP << " 입니다." << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
}

void Character::printcurrentstatus() const
{
    std::cout << "-----------Current Status: -----------\n";
    std::cout << "플레이어 " << name << "의 현재 상태입니다." << std::endl;
    std::cout << "Level : " << LevelComp->GetCurrentLevel() << std::endl;     // [한길] 레벨 출력 추가
    std::cout << "HP : " << HP << std::endl;
    std::cout << "Def : " << Def << std::endl;
    std::cout << "Att : " << Att << std::endl;
    std::cout << "Spd : " << Spd << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
}


void Character::EarnExp(float Amount)
{
    if (LevelComp != nullptr)
    {
        // LevelComponent의 경험치 추가 함수 호출
        LevelComp->GainExperience(Amount);    // [한길] 몬스터의 givingExp를 float으로 변경하여 형변환 필요 없어짐.
    }
}


void Character::ShowItems() const
{
    std::cout << "------------ 아이템창 ------------" << std::endl;

    if (items.empty())
    {
        std::cout << "아이템이 없습니다." << std::endl;
    }
    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            std::cout << i + 1 << ". "
                << items[i].GetName()
                << " (" << items[i].GetCount() << "개)" << std::endl;
        }
    }

    std::cout << "0. 취소" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

bool Character::UseItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size()))
    {
        std::cout << "잘못된 선택입니다." << std::endl;
        return false;
    }

    return items[index].Use(*this);
}


// Getter()
std::string Character::GetName() const
{
    return name;
}

int Character::GetHP() const
{
    return HP;
}

int Character::GetDef() const
{
    return Def;
}

int Character::GetAtt() const
{
    return Att;
}

int Character::GetSpd() const
{
    return Spd;
}

int Character::GetDam() const
{
    return Dam;
}



// Setter()
void Character::SetName(std::string InName)
{
    name = InName;
    return;
}

void Character::SetHP(int InHP)
{
    HP = InHP;
}

void Character::SetDef(int InDef)
{
    Def = InDef;
}

void Character::SetAtt(int InAtt)
{
    Att = InAtt;
}

void Character::SetSpd(int InSpd)
{
    Spd = InSpd;
}

void Character::AddItem(const Item& item)
{
    items.push_back(item);
}

