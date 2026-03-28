// BigNuguri.h

#pragma once
#include "Monster.h"

class BigNuguri : public Monster    
{
public:
    BigNuguri(int playerLevel);
    void Draw() const override;
};

