#include "Utill.h"
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <sstream>

using namespace std;

FileManager::FileManager() : mRankings() {
	cout << "생성됨!\n";
}

FileManager::~FileManager() {

}

void FileManager::RoadRanking() 
{
	// txt 파일에 저장된 랭킹 데이터를 mRankings 에 저장
	ifstream fin;
	

	fin.open("Ranking.txt" ); // 임시
	if (fin.is_open()) 
	{
		while (!fin.eof()) 
		{
			string str,tmp;
			int acc, time, cpm;
			getline(fin, tmp);
			istringstream iss(tmp);
			iss >> str >> acc >> time >> cpm;
			if (iss.fail())
			{
				break;
			}
			Ranking data(str, acc, time, cpm);
			mRankings.push_back(data);
		}
		fin.close();
	}
	else
	{
		ofstream fout;
		fout.open("Ranking.txt");
	}
	
}

void FileManager::SaveRanking() {
	// mRankings 에 저장된 랭킹 데이터를 txt 파일로 저장
	ofstream Write;
	string tmp;

	Write.open("Ranking.txt");
	for (int i = 0; i < mRankings.size(); i++) {
		tmp = "";
		tmp = tmp + mRankings[i].GetNick() + " " + to_string(mRankings[i].GetAccuracy()) + " " + to_string(mRankings[i].GetTime()) + " " + to_string(mRankings[i].GetCPM()) + "\n";
		Write.write(tmp.c_str(), tmp.size());
	}
	Write.close();
}

void FileManager::ShowRanking(Screen& screen) {

	string tmp;
	int x, y;

	x = 15;
	y = 15;

	for (int i = 0; i < mRankings.size(); i++) {
		tmp = "";
		tmp += (mRankings[i].GetNick() + ", ");
		tmp += to_string(mRankings[i].GetAccuracy()) + ", ";
		tmp += to_string(mRankings[i].GetTime()) + ", ";
		tmp += to_string(mRankings[i].GetCPM()) + "\n";
		Widget* temp = new Widget(tmp, x, (y + (2 * i)));
		screen.AddWidget(temp);
	}



}

void FileManager::Realignment(char Type, string Order) {

	Ranking tmp;

	if (Order == "UP") {
		switch (Type) {
		case 'N':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetNick() < mRankings[j].GetNick()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'A':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetAccuracy() < mRankings[j].GetAccuracy()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'T':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetTime() < mRankings[j].GetTime()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'C':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetCPM() < mRankings[j].GetCPM()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		}
	}
	else { // DOWN
		switch (Type) {
		case 'N':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetNick() > mRankings[j].GetNick()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'A':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetAccuracy() > mRankings[j].GetAccuracy()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'T':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetTime() > mRankings[j].GetTime()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case 'C':
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetCPM() > mRankings[j].GetCPM()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		}
	}

}


Ranking::Ranking() : mNick(""), mAccuracy(0), mTime(0), mCPM(0) {}

Ranking::Ranking(const string nick, const int acc, const int time, const int cpm) : mNick(nick), mAccuracy(acc), mTime(time), mCPM(cpm) {
}

Ranking::~Ranking() {}

void Ranking::Update(const string nick, const int acc, const int time, const int cpm) {
	mNick = nick;
	mAccuracy = acc;
	mTime = time;
	mCPM = cpm;
}

namespace console
{
	// http://www.cplusplus.com/forum/windows/121444/

	void SetColor(unsigned short color)

	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void SetWindowSize(int x, int y)
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

	void SetCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO cur;
		cur.bVisible = visible;
		cur.dwSize = 2;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	}
}