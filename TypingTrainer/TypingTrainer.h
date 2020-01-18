#pragma once
#include "Screen.h"
#include "Utill.h"
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class TypingTrainer {
public:
	TypingTrainer();
	TypingTrainer(const Screen& screen);
	~TypingTrainer();

	void ScreenSwitching(const Screen& screen);
	void UtillManageMent();

private:
	Screen Cur;						// 현재화면
	vector<Screen> mSubScreens;		// Cur 화면이 가지고 있는 위젯들의 화면

};