#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <string>
#include <vector>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

#define		WIDTH		90
#define		HEIGHT		40

#define		UP			72
#define		DOWN		80
#define		RIGHT		77
#define		LEFT		75

void TextColor(int font, int backGround);
void gotoxy(int x, int y);
