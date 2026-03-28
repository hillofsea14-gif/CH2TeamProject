// WildCat.h

#pragma once
#include "Monster.h"

class WildCat:public Monster
{
public:
    WildCat(int playerLevel);
    void Draw() const override;
};

