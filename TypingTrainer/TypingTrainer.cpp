// TypingTrainer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "Screen.h"
#include "Utill.h"

using namespace std;
// https://media.discordapp.net/attachments/293378188979994624/667216288782876702/unknown.png?width=481&height=670
//void PrintBuf(const vector<char>& buf)
//{
//    system("cls");
//    for (int i = 0; i < buf.size(); i++)
//    {
//        cout << buf[i];
//    }
//}

int main() 
{

	FileManager manager;

	manager.RoadRanking();
	manager.ShowRanking();
	manager.Realignment('A', "UP");
	manager.ShowRanking();
	//manager.SaveRanking();

	////FileManager manager;
 //    Screen sc(60,40);
 //    Widget t1("Typing Trainer", 20, 20);
 //   
 //    sc.AddWidget(t1);
 //    sc.Show();
 //    char a;
 //    cin >> a;
   
    //char c;
    //vector<char> buf;
    //while (true) 
    //{ 
    //    c = _getch();
    //    if (c == 27) {
    //        break;
    //    }

    //    if (c == '\b') {
    //        if (buf.empty() == false) {
    //            buf.pop_back();
    //        }
    //        //PrintBuf(buf);
    //        cout << "\b \b";
    //    }
    //    else if (c == 13) {
    //        cout << endl;
    //    }
    //    else {
    //        buf.push_back(c);
    //        cout << c;
    //    }
    //
    //}
    return 0;
}


