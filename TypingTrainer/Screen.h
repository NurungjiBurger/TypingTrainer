#pragma once
#include <string>
#include <vector>
#include "Widget.h"

class Widget;

class Screen
{
public:
	Screen();
	Screen(int x, int y);
	//Screen(const Screen& other);
	virtual ~Screen();
	void AddWidget(Widget* widget);
	void Show() const;

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
	int GetFocus() const { return mFocus; }
	const std::vector<Widget*>& GetWidgets()  {return mWidgets; }
	const std::vector<int>* GetSelectableIndices() { return &mSelectableIndices; }

	void SetWidth(int width) { mWidth = width; }
	void SetHeight(int height) { mHeight = height; }
	void SetFocus(int focus) { mFocus = focus; }

private:
	void SetSelectableIndices();
	int mWidth;
	int mHeight;
	int mFocus;

	std::vector<Widget*> mWidgets;
	std::vector<int> mSelectableIndices;
};


