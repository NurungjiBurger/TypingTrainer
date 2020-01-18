#include "TypingTrainer.h"

TypingTrainer::TypingTrainer() {

}

TypingTrainer::TypingTrainer(const Screen& screen) {
	
	Screen tmp;
	vector<Widget> widgets;

	Cur = screen;
	widgets = Cur.GetWidgets();

	for (int i = 0; i < widgets.size(); i++) {
		//tmp = widgets[i]; // 위젯 클래스에서 가리키는 특정 스크린을 뽑아서
		//mSubScreen.push_back(tmp); // 현재 스크린의 서브스크린들에 추가

	}
}

TypingTrainer::~TypingTrainer() {

}

void TypingTrainer::ScreenSwitching(const Screen& screen) { // 특정 스크린 자체를 변수로 받거나, 번호를 받아서 서브스크린에서 뽑아 사용
	screen.Show();
}

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