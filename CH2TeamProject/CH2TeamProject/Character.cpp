#include <iostream>
#include "Character.h"
#include "Item.h"
#include "LogManager.h"

Character::Character(std::string InName)
    : name(InName), CurrentHP(100), MaxHP(100), Def(10), Att(20), Spd(5), Dam(0), Gold(0)
{
    LevelComp = new LevelComponent();
}

Character::~Character()
{
    if (LevelComp != nullptr)
    {
        delete LevelComp;
        LevelComp = nullptr;
    }
}

void Character::attack(Character& character, Monster& monster)
{
    Dam = Att - monster.GetDef();

    if (Dam < 0)
    {
        Dam = 0;
    }

    monster.takeDamage(character);
}

void Character::takeDamage(Monster& monster)
{
    SetCurrentHP(CurrentHP - monster.GetDam());
}

void Character::printcurrentstatus() const
{
    std::cout << "-----------Current Status: -----------\n";
    std::cout << "플레이어 " << name << "의 현재 상태입니다." << std::endl;
    std::cout << "Level : " << LevelComp->GetCurrentLevel() << std::endl;
    std::cout << "HP : " << CurrentHP << "/" << MaxHP << std::endl;
    std::cout << "Def : " << Def << std::endl;
    std::cout << "Att : " << Att << std::endl;
    std::cout << "Spd : " << Spd << std::endl;
    std::cout << "Gold : " << Gold << "G." << std::endl;     // [한길] 추가
    std::cout << "---------------------------------------\n" << std::endl;
}

void Character::EarnExp(float Amount)
{
    if (LevelComp != nullptr)
    {
        LevelComp->GainExperience(Amount);
    }
}

void Character::EarnGold(Monster& monster)
{
    Gold += monster.GetGivingGold();
    std::cout << "\n몬스터 " << monster.GetName() << "을(를) 처치하여 " << monster.GetGivingGold() << " G. 를 획득하였습니다." << std::endl;
    std::cout << "현재 소지 Gold : " << Gold << std::endl;
}

void Character::ShowItems() const
{
    // 정보창 영역 초기화 느낌으로 덮어쓰기
    LogManager::PrintInfoBox("------------ 아이템창 ------------", 0);

    if (items.empty())
    {
        LogManager::PrintInfoBox("아이템이 없습니다.", 1);
        LogManager::PrintInfoBox("0. 취소", 2);
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            LogManager::PrintInfoBox("                                ", i + 1);
        }

        for (int i = 0; i < static_cast<int>(items.size()); i++)
        {
            LogManager::PrintInfoBox(
                std::to_string(i + 1) + ". " +
                items[i].GetName() + " (" +
                std::to_string(items[i].GetCount()) + "개)",
                i + 1
            );
        }

        LogManager::PrintInfoBox("0. 취소", static_cast<int>(items.size()) + 1);
    }
}

bool Character::UseItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size()))
    {
        LogManager::PrintBattleLog("잘못된 선택입니다.", 7);
        return false;
    }

    return items[index].Use(*this);
}


// Getter()
std::string Character::GetName() const
{
    return name;
}

int Character::GetCurrentHP() const
{
    return CurrentHP;
}

int Character::GetMaxHP() const
{
    return MaxHP;
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

int Character::GetGold() const
{
    return Gold;
}

// Setter()
void Character::SetName(std::string InName)
{
    name = InName;
}

void Character::SetCurrentHP(int InCurrentHP)
{
    CurrentHP = InCurrentHP;

    if (CurrentHP > MaxHP)
    {
        CurrentHP = MaxHP;
    }

    if (CurrentHP < 0)
    {
        CurrentHP = 0;
    }
}

void Character::SetMaxHP(int InMaxHP)
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
