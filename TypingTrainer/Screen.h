#pragma once

#include <string>
#include <vector>

using namespace std;

void SetConsoleWindowSize(int x, int y);


class Widget
{
public:
	//Widget();
	Widget(int x, int y);
	Widget(const std::string& s, int x, int y);
	//Widget(const Widget& other);

	virtual ~Widget();
	int GetX() const { return mX; }
	int GetY() const { return mY; }
	string GetString() const { return mStringData; }
	bool GetSelectable() const { return mSelectable; }

	void SetPos(int x, int y) { mX = x, mY = y; }
	void SetSelectable(bool selectable) { mSelectable = selectable; }
	void SetStringData(const std::string& s) { mStringData = s; }

private:
	int mX;
	int mY;
	bool mSelectable;
	std::string mStringData;
};


class Screen
{
public:
	Screen();
	Screen(int x, int y);
	//Screen(const Screen& other);
	virtual ~Screen();
	void AddWidget(const Widget& widget);
	void Show() const;

private:
	int mWidth;
	int mHeight;
	int mFocus;
	vector<Widget> mWidgets;
};