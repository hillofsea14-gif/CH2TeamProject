// LevelComponent.h

#pragma once

#include <cstdint>

class LevelComponent
{
public:
    LevelComponent();

    void GainExperience(float Amount);

    int32_t GetCurrentLevel() const { return CurrentLevel; }

    float GetExpRatio() const { return CurrentExp / MaxExp; }

private:
    int32_t CurrentLevel = 1;
    float CurrentExp = 0.0f;
    float MaxExp = 100.0f;

    void ProcessLevelUp();
};
