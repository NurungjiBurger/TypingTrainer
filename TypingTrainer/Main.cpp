// TypingTrainer.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "TypingTrainer.h"

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

	char c;

	c = _getch();
	
	if (c == 13) {

		system("cls");

		TypingTrainer trainer;

		trainer.UtillManageMent();
	}

	//FileManager manager;
//     Screen sc(60,40);
//     Widget t1("Typing Trainer", 20, 20);
//     sc.AddWidget(t1);
//     sc.Show();
//     char a;
//     cin >> a;

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



// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
