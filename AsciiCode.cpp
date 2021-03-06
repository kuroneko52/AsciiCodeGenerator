// AsciiCode.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

#define FILE_NAME "ascii.txt"

int main()
{
	int resultChar, len;
	char *str, c;
	const size_t BUFFER_SIZE = 255;
	ofstream outputfile(FILE_NAME);

	//メモリの動的確保
	str = new char[BUFFER_SIZE];

	while (1) {
		//インプット
		cin >> str;

		outputfile << str << endl;

		//入力文字数取得
		len = strlen(str);

		//一文字ずつの比較と表示
		for (int i = 0; i < len; i++) {
			//exitならプログラム終了
			if (!strncmp(str, "exit;", 5)) {
				exit(0);
			}

			//1文字取得
			c = *str;

			resultChar = c;

			//アウトプット
			cout << resultChar << " ";

			outputfile << resultChar << " ";

			//次の文字へ
			str++;
		}

		cout << endl;
		cout << endl;

		outputfile << endl << endl;
	}

	cout << endl;

	//ファイルクローズ
	outputfile.close();

	//メモリの解放
	delete[] str;

	return 0;
}
