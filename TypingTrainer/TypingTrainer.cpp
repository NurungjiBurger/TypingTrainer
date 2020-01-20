#include "TypingTrainer.h"

TypingTrainer::TypingTrainer() {
	Screen main(60, 40);
	Screen langugae(60, 40);
	Screen program(60, 40);
	Screen ranking(60, 40);
	Screen result(60, 40);

	Widget* programName = new Widget("Typing Trainer", 20, 20);
	Widget* startBM = new Button(&program, "시작하기", 20, 28);
	Widget* langugaeBM = new Button(&langugae, "지원 언어", 20, 30);
	Widget* rankingBM = new Button(&ranking, "랭킹", 20, 32);

	main.AddWidget(programName);
	main.AddWidget(startBM);
	main.AddWidget(langugaeBM);
	main.AddWidget(rankingBM);
	// Main 화면 구성

	
	// Program 화면 구성

	FileManager manager;

	manager.RoadRanking();
	manager.ShowRanking(ranking);

	Widget* mainBRA = new Button(&main, "뒤로가기", 10, 50);
	Widget* startBRA = new Button(&start, "시작하기", 50, 50);

	ranking.AddWidget(mainBRA);
	ranking.AddWidget(startBRA);

	// Ranking 화면 구성

	Widget* mainBRE = new Button(&main, "처음화면으로", 5, 50);
	Widget* rankingBRE = new Button(&ranking, "랭킹", 35, 50);

	result.AddWidget(mainBRE);
	result.AddWidget(rankingBRE);

	// Result 화면 구성

	cur = main;
	main.SetFocus(1);
	ranking.SetFocus(1);
	ScreenOperating();
}

TypingTrainer::~TypingTrainer() {

}

void TypingTrainer::ScreenOperating() { 

	char c;

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
			cout << focus << endl;
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

		else if (c == 77)
		{
			// right arrow
			int size = selectableIndices->size();
			int focus = cur.GetFocus();
			if (focus < size - 1)
			{
				cur.SetFocus(focus + 1);
			}
		}

		else if (c == 75) 
		{
			// left arrow
			int size = selectableIndices->size();
			int focus = cur.GetFocus();
			cout << focus << endl;
			if (focus > 0)
			{
				cur.SetFocus(focus - 1);
			}
		}

		else if (c == 32)
		{
			// space bar 
			int focus = cur.GetFocus();
			Screen* tmp = cur.GetWidgets()[selectableIndices->at(focus)]->GetNext();
			if (tmp != NULL)
			{
				cur = *tmp;
				selectableIndices = cur.GetSelectableIndices();

			}

		}




	} // 화면에 버튼이 있는 경우


	// 화면에 버튼이 없는 경우 ( 타자치는 곳 )
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