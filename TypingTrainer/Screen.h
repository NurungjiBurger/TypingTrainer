#pragma once
#include <string>
#include <vector>

using namespace std;

class Widget {
public :
	Widget();
	Widget(String s, int x, int y, bool select);
	Widget(const Widget& other);
	virtual ~Widget();

	int GetX() { return mX; }
	int GetY() { return mY; }
	string GetString() { return mStr; }
	bool GetSelectable() { return mSelect; }

	void SetCursor(int x, int y) { mX = x, mY = y; }
	void SetString(string str) { mStr = str; }
	void SetSelectable(bool v) { mSelect = v; }

private :
	int mX;
	int mY;
	string mStr;
	bool mSelect;

};

class Screen {
public :
	Screen();
	Screen(const Screen& other);
	virtual ~Screen();
	void AddData(const string& s,const int x,const int y,const bool select);
	void Show() const;

private :
	int mWidth;
	int mHeight;
	vector<Widget> mWidgets;

};