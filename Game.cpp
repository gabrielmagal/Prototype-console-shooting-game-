#include "Game.h"


void GameFunctions::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GameFunctions::drawMenu()
{
    for (int i = 0; i < 20; i++)
    {
        printf_s("_");
    }
    printf_s("\n");
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            if (i == 0 || i == 19)
                printf_s("|");
            else
                printf_s(" ");
        }
        printf_s("\n");
    }
    for (int i = 0; i < 20; i++)
    {
        printf_s("_");
    }
}


void GameFunctions::hotkey()
{
    if (GetAsyncKeyState(VK_LEFT) & 1)
    {
        if (!checkMove && (currentShotY == 0 || currentShotY == 20))
        {
            characterIndex = '<';
            gotoxy(currentX, currentY);
            printf_s(" ");
            currentX--;
            checkMove = true;
        }
    }

    if (GetAsyncKeyState(VK_RIGHT) & 1)
    {
        if (!checkMove && (currentShotY == 0 || currentShotY == 20))
        {
            characterIndex = '>';
            gotoxy(currentX, currentY);
            printf_s(" ");
            currentX++;
            checkMove = true;
        }
    }

    if (GetAsyncKeyState(VK_UP) & 1)
    {
        if (!checkMove && (currentShotY == 0 || currentShotY == 20))
        {
            characterIndex = '^';
            gotoxy(currentX, currentY);
            printf_s(" ");
            currentY--;
            checkMove = true;
        }
    }

    if (GetAsyncKeyState(VK_DOWN) & 1)
    {
        if (!checkMove && (currentShotY == 0 || currentShotY == 20))
        {
            characterIndex = 'v';
            gotoxy(currentX, currentY);
            printf_s(" ");
            currentY++;
            checkMove = true;
        }
    }

    if (GetAsyncKeyState(VK_SPACE) & 1) {
        if (!checkMove && (currentShotY == 0 || currentShotY == 20))
        {
            if (characterIndex == '^')
            {
                currentShotX = currentX;
                currentShotY = currentY;
            }

            if (characterIndex == 'v')
            {
                currentShotX = currentX;
                currentShotY = currentY;
            }
        }
    }
}


void GameFunctions::gameMovement()
{
    if (checkMove == true || (currentShotY > 0 && currentShotY < 20))
    {
        if (currentShotY > 0 && currentShotY < 20 && characterIndex == '^')
        {
            gotoxy(currentShotX, currentShotY);
            printf_s(" ");
            currentShotY--;
            gotoxy(currentShotX, currentShotY);
            printf_s("|");
            Sleep(30);
        }

        if (currentShotY > 0 && currentShotY < 20 && characterIndex == 'v')
        {
            gotoxy(currentShotX, currentShotY);
            printf_s(" ");
            currentShotY++;
            gotoxy(currentShotX, currentShotY);
            printf_s("|");
            Sleep(30);
        }

        if (currentShotY == 0 || currentShotY == 20)
        {
            gotoxy(currentShotX, currentShotY);
            printf_s("_");
        }

        if (currentX > 0 && currentX < 19 && currentY > 0 && currentY < 21)
        {
            gotoxy(currentX, currentY);
            printf_s("%c", characterIndex);
            checkMove = false;
        }
        else
        {
            system("cls");
            printf_s("Voce perdeu!");
            return;
        }
    }
}