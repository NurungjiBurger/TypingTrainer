#include <vector>
#include "Screen.h"

using namespace std;

Screen::Screen() {
	mWidth = 30;
	mHeight = 30;
	mWidgets = new Widget();
}
Screen::Screen(const Screen& other) {

}

virtual Screen::~Screen() {

}

void Screen::AddData(const string& s, const int x, const int y, const bool select) {

	Widget obj(s, x, y, select);

	mWidgets.push_back(obj);

}
void Screen::Show() const {
	
	COORD Cur;

	for (int i = 0; i < mWidgets.size(); i++) {
		Cur.X = mWidgets[i].GetX();
		Cur.Y = mWidgets[i].GetY();
		SetConsolCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << mWidgets[i].GetString();
	}

}

Widget::Widget() {

}

Widget::Widget(String s, int x, int y, bool select) {
	mX = x, mY = y, mStr = s, mSelect = select;
}

Widget::Widget(const Widget& other) {

}

virtual Widget::~Widget() {

}

