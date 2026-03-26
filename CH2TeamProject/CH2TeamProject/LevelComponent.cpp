// LevelComponent.cpp

#include "LevelComponent.h"

LevelComponent::LevelComponent()
{
    // 초기화 로직 (필요 시)
}

void LevelComponent::GainExperience(float Amount)
{
    if (Amount <= 0.f) return;

    CurrentExp += Amount;
    std::cout << "\\n[경험치 획득] +" << Amount << " EXP" << std::endl;

    // 경험치가 꽉 차면 레벨업(여러 레벨을 한 번에 올릴 수 있도록 while문 사용)
    while (CurrentExp >= MaxExp)
    {
        ProcessLevelUp();
    }

    std::cout << "[현재 상태] Level: " << CurrentLevel
        << " (Current: " << CurrentExp << " / Max: " << MaxExp << ")" << std::endl;

}

void LevelComponent::ProcessLevelUp()
{
    CurrentExp -= MaxExp;
    CurrentLevel++;

    // 다음 레벨 필요 경험치 20% 증가
    MaxExp *= 1.2f;

    std::cout << "\\n★ ★ ★ LEVEL UP! 현재 레벨: " << CurrentLevel << "★ ★ ★" << std::endl;

}
