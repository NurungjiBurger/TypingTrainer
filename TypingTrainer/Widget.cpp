#include <iostream>

#include <string>
#include "Widget.h"

using namespace std;

Widget::Widget(int x, int y)
	: mX(x)
	, mY(y)
	, mSelectable(false)
	, mStringData("")
{
}

Widget::Widget(const string& s, int x, int y) : mX(x), mY(y), mSelectable(false), mStringData(s) {

}

Screen* Widget::GetNext()
{
	return NULL;
}

Widget::~Widget()
{
}

Button::Button(int x, int y)
	:Widget(x, y)
	, mNext(NULL)
{
	mSelectable = true;
}

Button::Button(const string& s, int x, int y)
	: Widget(s, x, y)
	, mNext(NULL)
{
	mSelectable = true;
}

Button::Button(Screen* next, const string& s, int x, int y)
	: Widget(s, x, y)
	, mNext(next)
{
	mSelectable = true;
}

Button::~Button()
{
}