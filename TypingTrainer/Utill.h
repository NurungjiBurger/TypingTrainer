#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Ranking {
public:
	Ranking();
	Ranking(const string nick, const int acc, const int time, const int cpm);
	virtual ~Ranking();

	string GetNick() { return mNick; }
	int GetAccuracy() { return mAccuracy; }
	int GetTime() { return mTime; }
	int GetCPM() { return mCPM; }

	void Update(const string nick, const int acc, const int time, const int cpm);

private:
	string mNick;
	int mAccuracy;
	int mTime;
	int mCPM;
};

class FileManager{
public :
	FileManager();
	virtual ~FileManager();
	
	void RoadRanking();

	void SaveRanking();

	void Realignment(char Type, string Order);

	void ShowRanking();

private :
	vector<Ranking> mRankings;

};

namespace console
{
	void SetWindowSize(int x, int y);
	void SetColor(unsigned short color);
	void SetCursorVisible(bool visible);
}