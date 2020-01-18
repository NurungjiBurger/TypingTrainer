#include "TypingTrainer.h"

TypingTrainer::TypingTrainer() {
	Screen main(60, 40);
	Screen langugae(60, 40);
	Screen program(60, 40);
	Screen ranking(60, 40);
	Screen result(60, 40);

	Widget* programName = new Widget("Typing Trainer", 20, 20);
	Widget* startB = new Button(&program, "시작하기", 20, 28);
	Widget* langugaeB = new Button(&langugae, "지원 언어", 20, 30);
	Widget* rankingB = new Button(&ranking, "랭킹", 20, 32);

	main.AddWidget(programName);
	main.AddWidget(startB);
	main.AddWidget(langugaeB);
	main.AddWidget(rankingB);
	// Main 화면 구성

	
	// Program 화면 구성

	FileManager manager;

	manager.RoadRanking();
	manager.ShowRanking(ranking);

	// Ranking 화면 구성



	// Result 화면 구성

	cur = main;
	main.SetFocus(1);
	ScreenSwitching();
}

TypingTrainer::~TypingTrainer() {

}

void TypingTrainer::ScreenSwitching() { 

	char c;
	vector<char> buf;

	const vector<int>* selectableIndices = cur.GetSelectableIndices();
	while (true)
	{
		cur.Show();
		c = _getch();
		if (c == 27) {
			break;
		}

		if (c == 72)
		{
			// upwards arrow
			int size = selectableIndices->size();
			int focus = cur.GetFocus();
			if (focus > 0)
			{
				cur.SetFocus(focus - 1);
			}

		}
		else if (c == 80)
		{
			// downwards arrow
			int size = selectableIndices->size();
			int focus = cur.GetFocus();
			if (focus < size - 1)
			{
				cur.SetFocus(focus + 1);
			}
		}
		else if (c == 32)
		{
			int focus = cur.GetFocus();
			Screen* tmp = cur.GetWidgets()[selectableIndices->at(focus)]->GetNext();
			if (tmp != NULL)
			{
				cur = *tmp;
				selectableIndices = cur.GetSelectableIndices();
			}

		}


	}
}

void TypingTrainer::UtillManageMent(Screen& screen) {

	char type, order;

	FileManager manager;

	manager.RoadRanking();
	manager.ShowRanking(screen);

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

	}


}