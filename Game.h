#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

static int currentX = 2;
static int currentY = 1;
static int currentShotX = 0;
static int currentShotY = 0;
static bool checkMove = true;
static char characterIndex = '^';

class GameFunctions
{
public:
	static void gotoxy(int x, int y);
	static void drawMenu();
	static void hotkey();
	static void gameMovement();
};