#include "Screen.h"
#include "Utill.h"
#include <iostream>
#include <Windows.h>

#include <conio.h>
#include <iomanip>
#include <stdexcept>

using namespace std;


Screen::Screen()
	: mWidth(60),
	mHeight(30),
	mFocus(0),
	mWidgets(),
	mSelectableIndices()
{
}

Screen::Screen(int x, int y)
	: mWidth(x), mHeight(y), mFocus(0), mWidgets(), mSelectableIndices()
{
}

Screen::~Screen()
{
}

void Screen::SetSelectableIndices()
{
	for (int i = 0; i < mWidgets.size(); i++)
	{
		if (mWidgets[i]->GetSelectable())
		{
			mSelectableIndices.push_back(i);
		}
	}
}

void Screen::Show() const {

	COORD cur;

	system("cls");
	console::SetCursorVisible(false);
    console::SetWindowSize(mWidth, mHeight);

    cur.X = 0;
    cur.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    cout << setw(mWidth) << setfill('=') << "" ;
	

	for (size_t i = 0; i < mWidgets.size(); i++) 
	{
		cur.X = mWidgets[i]->GetX();
		cur.Y = mWidgets[i]->GetY();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

		if (mWidgets[i]->GetSelectable())
		{
			console::SetColor(FOREGROUND_BLUE);
			if (i == mSelectableIndices[mFocus])
			{
				console::SetColor(BACKGROUND_GREEN);
			}
			
			
		}
		cout << mWidgets[i]->GetString();
	}

    cur.X = 0;
    cur.Y = mHeight-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	console::SetColor(7);
    cout << setw(mWidth) << setfill('=') << "";
	
}

void Screen::AddWidget(Widget* obj) {

	mWidgets.push_back(obj);
	SetSelectableIndices();

}

