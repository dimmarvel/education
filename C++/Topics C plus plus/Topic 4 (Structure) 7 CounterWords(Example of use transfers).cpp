#include<iostream>
#include<conio.h>  //getche()
#include <stdio.h>
//подсчет слов на структуре перечисления 160стр.
using namespace std;
//объявление перечисляемого типа
enum itsaWord { NO, YES };

int main() {
	setlocale(LC_ALL, "Rus");
	itsaWord isWord = NO;
	char ch = 'a';
	int wordcount = 0;
	cout << "Input words: \n\a";
	do {
		ch = getchar();
		if (ch == ' ' || ch == '\r') {
			if (isWord == YES) {
				++wordcount;
				isWord = NO;
			}
		}
		else
			if (isWord == NO)
				isWord = YES;
	} while (ch != '\n');
	cout << "\n ---Count word: " << wordcount << "---\n";
	system("pause");
}