#include "Utill.h"
using namespace std;

FileManager::FileManager() : mRankings() {
	cout << "생성됨!\n";
}

FileManager::~FileManager() {

}

void FileManager::RoadRanking() {
	// txt 파일에 저장된 랭킹 데이터를 mRankings 에 저장
	ifstream Read;

	Read.open("Ranking.txt"); // 임시
	if (Read.is_open()) {
		while (!Read.eof()) {
			string tmp;
			string nick;
			int acc, time, cpm;
			getline(Read, tmp);


		}
		Read.close();
	}
	else cout << "파일이 존재하지 않습니다.";
}

void FileManager::SaveRanking() {
	// mRankings 에 저장된 랭킹 데이터를 txt 파일로 저장
	ofstream Write;
	string tmp;

	Write.open("Ranking.txt");
	for (int i = 0; i < mRankings.size(); i++) {
		tmp = "";
		tmp = tmp + mRankings[i].GetNick() + "," + to_string(mRankings[i].GetAccuracy()) + "," + to_string(mRankings[i].GetTime()) + "," + to_string(mRankings[i].GetCPM()) + "\n";
		Write.write(tmp.c_str(), tmp.size());
	}
	Write.close();
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