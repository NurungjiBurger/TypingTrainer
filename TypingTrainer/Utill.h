#pragma once

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

private :
	vector<Ranking> mRankings;

};

