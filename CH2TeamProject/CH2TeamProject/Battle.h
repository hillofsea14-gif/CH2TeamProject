// Battle.cpp

#include "Character.h"
#include "LogManager.h"
#include "Render.h"

bool IsPlayerFast(Character& character, Monster& monster);


void PAttack(Character& character, Monster& monster);


void MAttack(Character& character, Monster& monster);


int Battle(Character& character, Monster& monster);   // [한길] 3.31 죽었을 때 페이지 만들기 위해 반환값 자료형 int로 수정.
