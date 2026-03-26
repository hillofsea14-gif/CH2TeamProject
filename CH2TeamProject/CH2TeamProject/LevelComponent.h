// LevelComponent.h


#pragma once

#include <iostream>

class LevelComponent
{
public:
    LevelComponent();

    /** 경험치를 추가합니다. (전투 파트에서 몬스터 처치 시 호출) */
    void GainExperience(float Amount);

    /** 현재 레벨을 반환합니다. */
    int32_t GetCurrentLevel() const { return CurrentLevel; }

    /** 현재 경험치 비율을 반환합니다. (0.0 ~ 1.0) */
    float GetExpRatio() const { return CurrentExp / MaxExp; }

private:
    int32_t CurrentLevel = 1;
    float CurrentExp = 0.0f;
    float MaxExp = 100.0f;

    /** 레벨업 로직 처리 */
    void ProcessLevelUp();
};
