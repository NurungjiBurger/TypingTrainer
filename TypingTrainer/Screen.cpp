#include "Screen.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <stdexcept>

using namespace std;

// http://www.cplusplus.com/forum/windows/121444/
void SetConsoleWindowSize(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (h == INVALID_HANDLE_VALUE)
        throw std::runtime_error("Unable to get stdout handle.");

    // If either dimension is greater than the largest console window we can have,
    // there is no point in attempting the change.
    {
        COORD largestSize = GetLargestConsoleWindowSize(h);
        if (x > largestSize.X)
            throw std::invalid_argument("The x dimension is too large.");
        if (y > largestSize.Y)
            throw std::invalid_argument("The y dimension is too large.");
    }


    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
        throw std::runtime_error("Unable to retrieve screen buffer info.");

    SMALL_RECT& winInfo = bufferInfo.srWindow;
    COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

    if (windowSize.X > x || windowSize.Y > y)
    {
        // window size needs to be adjusted before the buffer size can be reduced.
        SMALL_RECT info =
        {
            0,
            0,
            x < windowSize.X ? x - 1 : windowSize.X - 1,
            y < windowSize.Y ? y - 1 : windowSize.Y - 1
        };

        if (!SetConsoleWindowInfo(h, TRUE, &info))
            throw std::runtime_error("Unable to resize window before resizing buffer.");
    }

    COORD size = { x, y };
    if (!SetConsoleScreenBufferSize(h, size))
        throw std::runtime_error("Unable to resize screen buffer.");


    SMALL_RECT info = { 0, 0, x - 1, y - 1 };
    if (!SetConsoleWindowInfo(h, TRUE, &info))
        throw std::runtime_error("Unable to resize window after resizing buffer.");
}


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

	COORD Cur;
    SetConsoleWindowSize(mWidth, mHeight);
	

	for (size_t i = 0; i < mWidgets.size(); i++) {
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

Widget::~Widget()
{
}