#include "TypingTrainer.h"

TypingTrainer::TypingTrainer() {

}

TypingTrainer::TypingTrainer(const Screen& screen) {
	Cur = screen;
}

TypingTrainer::~TypingTrainer() {

}

void TypingTrainer::ScreenSwitching(const Screen& screen) { 
	screen.Show();
} // 버튼 객체에서 가져온 스크린 정보로 스크린 교체
// 필요시 addwidget 추가

void TypingTrainer::UtillManageMent() {

	char type, order;

	FileManager manager;

	manager.RoadRanking();
	manager.showRanking();

	while (true)
	{

		type = _getch();
		if (type == 27) {
			break;
		}

		cout << type;

		order = _getch();
		order = _getch();

		if (type == 'a' || type == 'c' || type == 't' || type == 'n') {
			type = type - 32;
			if ((int)order == 72) manager.Realignment(type, "UP");
			else if ((int)order == 80) manager.Realignment(type, "DOWN");
		}

		system("cls");

		manager.showRanking();
		
	}


}