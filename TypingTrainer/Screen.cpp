#include "Screen.h"
#include <iostream>
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

Widget::Widget(int x, int y)
	: mX(x)
	, mY(y)
	, mSelectable(false)
	, mStringData("")
{
}

Widget::~Widget()
{
}