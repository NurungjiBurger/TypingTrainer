#include "Utill.h"
#include <iostream>
using namespace std;

Ranking::Ranking() {}

Ranking::Ranking(const string nick, const int acc, const int time, const int cpm) {
	mNick = nick;
	mAccuracy = acc;
	mTime = time;
	mCPM = cpm;
}


Ranking::~Ranking() {}





FileManager::FileManager() {
	mRankings();
	cout << "������!\n";
}

FileManager::~FileManager() {}

void FileManager::RoadRanking() {
	// txt ���Ͽ� ����� ��ŷ �����͸� mRankings �� ����
	ifstream Read;

	Read.open("Ranking.txt"); // �ӽ�
	if (Read.is_open()) {
		while (!Read.eof()) {
			string tmp;
			string nick;
			int acc, time, cpm;
			getline(Read, tmp);


		}
		Read.close();
	}
	else cout << "������ �������� �ʽ��ϴ�.";
}

void FileManager::SaveRanking() {
	// mRankings �� ����� ��ŷ �����͸� txt ���Ϸ� ����
	ofstream Write;
	string tmp;

	Write.open("Ranking.txt");
	for (int i = 0; i < mRankings.size(); i++) {
		tmp = "";
		tmp = tmp + mRankings[i].GetNick() + "," + mRankings[i].GetAccuracy() + "," + mRankings[i].GetTime() + "," + mRankings[i].GetCPM() + "\n";
		Write.write(tmp.c_str(), tmp.size());
	}
	Write.close();
}

void FileManager::Realignment(string Type, string Order) {

	Ranking tmp;

	if (order == "UP") {
		switch (Type) {
		case "Nick": 
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetNick() < mRankings[j].GetNIck()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case "Accuracy": 
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
		case "Time": 
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
		case "CPM": 
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
		case "Nick":
			for (int i = 0; i < mRankings.size(); i++) {
				for (int j = i + 1; j < mRankings.size(); j++) {
					if (mRankings[i].GetNick() > mRankings[j].GetNIck()) {
						tmp = mRankings[i];
						mRankings[i] = mRankings[j];
						mRankings[j] = tmp;
					}
				}
			}
			break;
		case "Accuracy":
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
		case "Time":
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
		case "CPM":
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
