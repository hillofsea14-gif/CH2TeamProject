#include <iostream>
#include "Character.h"
#include "Item.h"
#include "LogManager.h"

Character::Character(std::string InName)
    : name(InName), CurrentHP(100), MaxHP(100), Def(5), Att(1000), Spd(500), Dam(0), Gold(0) // [승민] 3.30 초기 스탯 변경 [한길] 3.31 빠른 클리어 위해 초기 스탯 변경.
{
    LevelComp = new LevelComponent(this);
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
}

// 개수가 0이 된 아이템을 리스트에서 완전히 제거
void Character::RemoveItem(std::shared_ptr<Item> item)    //[한길] 3.30 추가. 
{
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
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
                items[i]->GetName() + " (" +         //[한길] 수정 items[index]가 이제 포인터이므로.대신->사용.
                std::to_string(items[i]->GetCount()) + "개)",
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

    return items[index]->Use(*this);
}

void Character::SetGold(int InGold)    // [한길] 상점 위해 추가.
{
    Gold = InGold;
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

float Character::GetCurrentExp() const
{
    return LevelComp->GetCurrentExp();
}

float Character::GetMaxExp() const
{
    return LevelComp->GetMaxExp();
}

int Character::GetLevel() const      // [한길] 3.30 추가
{
    return LevelComp->GetCurrentLevel();
}

const std::vector<std::shared_ptr<Item>>& Character::GetItems() const  // [한길] 아이템 출력 위한 Getter 추가.
{
    return items;
}

std::shared_ptr<Item> Character::FindItemByName(const std::string& itemName) // [한길] 3.30 추가
{
    for (auto& item : items) {
        if (item->GetName() == itemName) {
            return item; // 찾으면 해당 스마트 포인터 반환
        }
    }
    return nullptr; // 없으면 nullptr 반환
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

void Character::AddItem(std::shared_ptr<Item> newItem) //[한길] 아이템 더하는데에 사용.
{
    // 가방(items)에 똑같은 이름의 아이템이 있는지 찾기.
    for (auto& inventoryItem : items)
    {
        if (inventoryItem->GetName() == newItem->GetName())
        {
            // 같은 이름의 아이템을 찾았다면, 개수(Count)만 더하기.
            inventoryItem->AddCount(newItem->GetCount());

            // 개수를 합쳤으니 함수를 종료. (새로 추가하지 않음)
            return;
        }
    }
    items.push_back(newItem);
}

