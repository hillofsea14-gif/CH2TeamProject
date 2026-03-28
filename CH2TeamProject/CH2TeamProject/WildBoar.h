// WildBoar.h

#pragma once
#include "Monster.h"
class WildBoar : public Monster
{
public:
    WildBoar(int playerLevel);
    void Draw() const override;
};

