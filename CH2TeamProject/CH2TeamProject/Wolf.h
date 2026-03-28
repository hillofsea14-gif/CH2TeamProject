// Wolf.h

#pragma once
#include "Monster.h"

class Wolf : public Monster 
{
public:
    Wolf(int playerLevel);
    void Draw() const override;
};





