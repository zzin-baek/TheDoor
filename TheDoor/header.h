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

// �ܼ� â�� �⺻ ũ��(WIDTH, HEIGHT)
#define		WIDTH		90
#define		HEIGHT		40

// ����Ű �ƽ�Ű �ڵ� ��
#define		UP			72
#define		DOWN		80
#define		RIGHT		77
#define		LEFT		75

// ��Ʈ�� ��� ���� �Լ�
void TextColor(int font, int backGround);
// Ŀ���� ��ġ�� �����ϱ� ���� �Լ�
void gotoxy(int x, int y);
