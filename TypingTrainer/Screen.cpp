#include "Screen.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Screen::Screen()
	: mWidth(40),
	mHeight(40),
	mFocus(0),
	mWidgets()
{
	cout << "spawned!" << endl;
}

Screen::~Screen()
{

}

void Screen::AddWidget(const Widget& obj) {

	mWidgets.push_back(obj);

}
void Screen::Show() const {

	COORD Cur;

	for (int i = 0; i < mWidgets.size(); i++) {
		Cur.X = mWidgets[i].GetX();
		Cur.Y = mWidgets[i].GetY();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << mWidgets[i].GetString();
	}

}

Widget::Widget(int x, int y)
	: mX(x)
	, mY(y)
	, mSelectable(false)
	, mStringData("")
{
}

Widget::Widget(const std::string& s, int x, int y) : mX(x), mY(y), mSelectable(false), mStringData(s) {

}

Widget::~Widget()
{
}