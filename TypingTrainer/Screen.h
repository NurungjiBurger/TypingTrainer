#pragma once
#include <string>
#include <vector>

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
	bool GetSelectable() const { return mSelectable; }
	std::string GetString() const { return mStringData; }
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

	std::vector<Widget> mWidgets;
};


class Button : public Widget
{
public:
	Button(int x, int y);
	Button(const std::string& s, int x, int y);
	Button(Screen* next, const std::string& s, int x, int y);
	virtual ~Button();
	Screen* GetNext() const { return mNext; }
	void SetNext(Screen* next);

private:
	Screen* mNext;
};
