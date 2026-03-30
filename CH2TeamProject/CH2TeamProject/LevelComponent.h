// LevelComponent.h

#pragma once

#include <cstdint>

class Character; // [승민] Character 클래스와의 순환 참조 방지 위해 전방 선언.

class LevelComponent
{
public:
    LevelComponent(Character* InCharacter);

    void GainExperience(int Amount); // [승민] 정수로 출력하기 위해서 int로 통일.

    int32_t GetCurrentLevel() const { return CurrentLevel; }

    float GetExpRatio() const { return CurrentExp / MaxExp; }

    float GetCurrentExp() const { return CurrentExp; }
    float GetMaxExp() const { return MaxExp; }   //[성윤] 경험치바 UI 위해 Getter 추가.

    void ProcessLevelUp();

protected:
    int32_t CurrentLevel = 1;
    int CurrentExp = 0; // [승민] 정수로 출력하기 위해서 int로 통일.
    int MaxExp = 100; // [승민] 정수로 출력하기 위해서 int로 통일.
    Character* character; // [승민] 레벨업 시 캐릭터 스탯 증가를 위해 Character 객체 생성.
};
