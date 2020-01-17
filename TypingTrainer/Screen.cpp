#include "Screen.h"
#include "Utill.h"
#include <iostream>
#include <Windows.h>

#include <conio.h>
#include <iomanip>
#include <stdexcept>

using namespace std;


Screen::Screen()
	: mWidth(60),
	mHeight(30),
	mFocus(0),
	mWidgets()
{
}

Screen::Screen(int x, int y)
	: mWidth(x), mHeight(y), mFocus(0), mWidgets()
{
}

Screen::~Screen()
{
}

void Screen::Show() const {

	COORD cur;
	console::SetCursorVisible(false);
    console::SetWindowSize(mWidth, mHeight);
	console::SetColor(FOREGROUND_BLUE | BACKGROUND_GREEN);

    cur.X = 0;
    cur.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    cout << setw(mWidth) << setfill('=') << "" ;
	

	for (size_t i = 0; i < mWidgets.size(); i++) {
		cur.X = mWidgets[i].GetX();
		cur.Y = mWidgets[i].GetY();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << mWidgets[i].GetString();
	}

    cur.X = 0;
    cur.Y = mHeight-1;
	console::SetColor(FOREGROUND_BLUE | BACKGROUND_RED);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    cout << setw(mWidth) << setfill('=') << "";
    //cout << setfill(' ');

}

void Screen::AddWidget(const Widget& obj) {

	mWidgets.push_back(obj);

}

Widget::Widget(int x, int y)
	: mX(x)
	, mY(y)
	, mSelectable(false)
	, mStringData("")
{
}

Widget::Widget(const string& s, int x, int y) : mX(x), mY(y), mSelectable(false), mStringData(s) {

}

Widget::~Widget()
{
}

Button::Button(int x, int y)
	:Widget(x, y)
	, mNext(NULL)
{
}

Button::Button(const string& s, int x, int y)
	: Widget(s, x, y)
	, mNext(NULL)
{
}

Button::Button(Screen* next, const string& s, int x, int y)
	: Widget(s, x, y)
	, mNext(next)
{
}

Button::~Button()
{
}