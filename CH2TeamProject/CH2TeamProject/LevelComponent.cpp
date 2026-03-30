// LevelComponent.cpp

#include "LevelComponent.h"
#include "Character.h"
#include <iostream>

LevelComponent::LevelComponent(Character* InCharacter)
    : character(InCharacter)
{
     // 초기화 로직 (필요 시)
}

void LevelComponent::GainExperience(int Amount) // [승민] 정수로 출력하기 위해서 int로 통일.
{
    if (Amount <= 0) return;

    CurrentExp += Amount;
    //std::cout << "\\n[경험치 획득] +" << Amount << " EXP" << std::endl;

    // 경험치가 꽉 차면 레벨업(여러 레벨을 한 번에 올릴 수 있도록 while문 사용)
    while (CurrentExp >= MaxExp)
    {
        ProcessLevelUp();
    }

    //std::cout << "[현재 상태] Level: " << CurrentLevel
      //  << " (Current: " << CurrentExp << " / Max: " << MaxExp << ")" << std::endl;

}

void LevelComponent::ProcessLevelUp()
{
    CurrentExp -= MaxExp;
    CurrentLevel++;
    character->SetMaxHP(character->GetMaxHP() + 10); // [승민] 3.30 레벨업 시 최대 HP 증가
    character->SetCurrentHP(character->GetMaxHP()); // [승민] 3.30 레벨업 시 현재 HP를 최대 HP로 설정
    character->SetAtt(character->GetAtt() + 5); // [승민] 3.30 레벨업 시 공격력 증가
    character->SetDef(character->GetDef() + 2); // [승민] 3.30 레벨업 시 방어력 증가
    character->SetSpd(character->GetSpd() + 1); // [승민] 3.30 레벨업 시 속도 증가
    // 다음 레벨 필요 경험치 20% 증가
    MaxExp *= 1.2f;

    //std::cout << "\\n★ ★ ★ LEVEL UP! 현재 레벨: " << CurrentLevel << "★ ★ ★" << std::endl;

}
