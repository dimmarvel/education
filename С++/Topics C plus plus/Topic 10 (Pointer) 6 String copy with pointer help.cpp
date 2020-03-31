// copystr.cpp
// копирует одну строку в другую
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"rus");
	void copystr(char*, const char*); // прототип функции
	const char* str1 = "Поспешишь – людей насмешишь!";
	char str2[80];                    // пустая строка

	copystr(str2, str1);              // копируем строку str1 в str2
	cout << str2 << endl;                // и показываем результат
	system("pause");
	return 0;
}
void copystr(char* dest, const char* str)
{
	while (*str)      // пока не встретим конец строки
		*dest++ = *str++; // копируем ее
	*dest = '\0';       // заканчиваем строку
}