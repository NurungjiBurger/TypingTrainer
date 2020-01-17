#pragma once
#include "Screen.h"
#include "Utill.h"

class TypingTrainer {
public:
	TypingTrainer();
	~TypingTrainer();

	void ScreenSwitching();
	void UtillManageMent(char Type);

private:
	Screen Cur;

};