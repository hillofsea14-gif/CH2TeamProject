// Slime.cpp

#include "Slime.h"
#include "Character.h"
#include <iostream>
#include <string>

Slime::Slime() : Monster("슬라임")
{
    SetMaxHP(30);
    SetCurrentHP(30);
    SetAtt(5);
    SetDef(2);
    SetSpd(3);

}
