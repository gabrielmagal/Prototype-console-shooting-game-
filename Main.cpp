#include "Game.h"

GameFunctions AcessGameFunctions = GameFunctions();

int main()
{
    AcessGameFunctions.drawMenu();
    while (TRUE)
    {
        AcessGameFunctions.hotkey();
        AcessGameFunctions.gameMovement();
    }
}