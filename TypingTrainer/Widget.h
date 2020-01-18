#pragma once
#include <string>
#include <vector>
#include "Screen.h"

class Screen;

class Widget
{
public:
	//Widget();
	Widget(int x, int y);
	Widget(const std::string& s, int x, int y);
	//Widget(const Widget& other);
	virtual ~Widget();

	virtual Screen* GetNext();
	int GetX() const { return mX; }
	int GetY() const { return mY; }
	bool GetSelectable() const { return mSelectable; }
	std::string GetString() const { return mStringData; }
	void SetPos(int x, int y) { mX = x, mY = y; }
	void SetSelectable(bool selectable) { mSelectable = selectable; }
	void SetStringData(const std::string& s) { mStringData = s; }

protected:
	bool mSelectable;

private:
	int mX;
	int mY;

	std::string mStringData;
};

class Button : public Widget
{
public:
	Button(int x, int y);
	Button(const std::string& s, int x, int y);
	Button(Screen* next, const std::string& s, int x, int y);
	virtual ~Button();
	virtual Screen* GetNext() { return mNext; }
	void SetNext(Screen* next) { mNext = next; }

private:
	Screen* mNext;
};
