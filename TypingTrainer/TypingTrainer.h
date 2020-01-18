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
	~TypingTrainer();


	void ScreenSwitching();
	void UtillManageMent(Screen& screen);

private:
	Screen main, langugae, start, ranking, cur, result;


};