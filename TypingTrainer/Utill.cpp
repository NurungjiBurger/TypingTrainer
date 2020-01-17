#include "Utill.h"
using namespace std;

FileManager::FileManager() : mRankings() {

}

FileManager::~FileManager() {

}

void FileManager::RoadRanking()
{
	// txt 파일에 저장된 랭킹 데이터를 mRankings 에 저장
	ifstream fin;


	fin.open("Ranking.txt"); // 임시
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string str, tmp;
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
	ofstream fout;
	string tmp;

	fout.open("Ranking.txt");
	for (int i = 0; i < mRankings.size(); i++) {
		if (i == 0) tmp = "";
		else tmp = "\n";
		tmp = tmp + mRankings[i].GetNick() + " " + to_string(mRankings[i].GetAccuracy()) + " " + to_string(mRankings[i].GetTime()) + " " + to_string(mRankings[i].GetCPM());
		fout.write(tmp.c_str(), tmp.size());
	}
	fout.close();
}

void FileManager::showRanking() {
	for (int i = 0; i < mRankings.size(); i++) {
		cout << mRankings[i].GetNick() << ", " << mRankings[i].GetAccuracy() << ", " << mRankings[i].GetTime() << ", " << mRankings[i].GetCPM() << "\n";
	}
}

void DataSwap(Ranking &a, Ranking &b) {
	Ranking tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void FileManager::Realignment(char Type, string Order) {

	Ranking tmp;

	if (Order == "UP") {
		for (int i = 0; i < mRankings.size(); i++) {
			for (int j = i + 1; j < mRankings.size(); j++) {
				switch (Type) {
				case 'N':
					if (mRankings[i].GetNick() < mRankings[j].GetNick()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'A':
					if (mRankings[i].GetAccuracy() < mRankings[j].GetAccuracy()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'T':
					if (mRankings[i].GetTime() < mRankings[j].GetTime()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'C':
					if (mRankings[i].GetCPM() < mRankings[j].GetCPM()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				}
			}
		}
	}
	else { // DOWN
		for (int i = 0; i < mRankings.size(); i++) {
			for (int j = i + 1; j < mRankings.size(); j++) {
				switch (Type) {
				case 'N':
					if (mRankings[i].GetNick() > mRankings[j].GetNick()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'A':
					if (mRankings[i].GetAccuracy() > mRankings[j].GetAccuracy()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'T':
					if (mRankings[i].GetTime() > mRankings[j].GetTime()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				case 'C':
					if (mRankings[i].GetCPM() > mRankings[j].GetCPM()) {
						DataSwap(mRankings[i], mRankings[j]);
					}
					break;
				}
			}
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