// strplus.cpp
// перегрузка операции + дл€ строк
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdlib.h> // дл€ функции exit
#include <string.h> // дл€ функций strcpy, strcat
///////////////////////////////////////////////////////////
class String // наш класс дл€ строк
{
private:
    enum
    {
        SZ = 80
    };            // максимальный размер строки
    char str[SZ]; // массив дл€ строки
public:
    // конструктор без параметров
    String() { strcpy(str, ""); }
    // конструктор с одним параметром
    String(const char s[]) { strcpy(str, s); }
    // показ строки
    void display() const { cout << str; }
    String operator+=(String s22)
    {
        if (strlen(str) + strlen(s22.str) < SZ)
        {
            strcat(str, s22.str); // добавл€ем содержимое второй строки
        }
        else
        {
            cout << "\nѕереполнение!";
            exit(1);
        }
        return String(str); // возвращаем результат
    }
};
///////////////////////////////////////////////////////////
int main()
{

    setlocale(LC_ALL, "Rus");
    String s1 = "–ождеством!";    // используем конструктор с параметром
    String s2 = "— Ќовым годом!"; // используем конструктор с параметром
    String s3;                    // используем конструктор с параметром

    // показываем строки
    cout << "s1 ";
    s1.display();
    cout << "s2 ";
    s2.display();

    s3 = s1 += s2; // присваиваем строке s3 результат сложени€ строк s1 и s2

    cout << "s3 ";
    s3.display(); // показываем результат
    cout << endl;
    system("pause");
    return 0;
}
