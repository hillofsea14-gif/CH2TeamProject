// Render.h

#include <iostream>
#include "LogManager.h"
#include "Character.h"

void WaitForNext();

void ShowMainScreen(Character& character);




bool ReadIntAt(int x, int y, int& outValue);


bool OpenItemMenu(Character& character);


void RefreshBattleScreen(Character& character, Monster& monster);

