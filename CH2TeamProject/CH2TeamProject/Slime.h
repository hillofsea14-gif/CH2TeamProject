// Slime.h

#pragma once
#include "Character.h"
#include "Monster.h"
#include <string>

class Slime : public Monster
{
public:
    Slime();
    void Draw() const override;
};
