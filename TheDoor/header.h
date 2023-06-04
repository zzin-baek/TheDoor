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

// 콘솔 창의 기본 크기(WIDTH, HEIGHT)
#define		WIDTH		90
#define		HEIGHT		40

// 방향키 아스키 코드 값
#define		UP			72
#define		DOWN		80
#define		RIGHT		77
#define		LEFT		75

// 도트를 찍기 위한 함수
void TextColor(int font, int backGround);
// 커서의 위치를 변경하기 위한 함수
void gotoxy(int x, int y);
