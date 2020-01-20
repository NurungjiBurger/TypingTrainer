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


	void ScreenOperating();
	void UtillManageMent(Screen& screen);

private:
	Screen main, langugae, start, ranking, cur, result;
	vector<char> buf;


};