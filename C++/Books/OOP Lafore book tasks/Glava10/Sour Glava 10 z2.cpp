// newstr.cpp
// использование оператора new дл€ выделени€ пам€ти под строку
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class String
{
private:
    char* str; // указатель на строку
public:
    String(const char* s) // конструктор с одним параметром
    {
        int length = strlen(s);     // вычисл€ем длину строки
        str = new char[length + 1]; // выдел€ем необходимую пам€ть
        strcpy(str, s);             // копируем строку
    }
    ~String() // деструктор
    {
        cout << "”дал€ем строку\n";
        delete[] str; // освобождаем пам€ть
    }
    void display() // покажем строку на экране
    {
        cout << str << endl;
    }
    void upit()
    {
        int length = strlen(this->str);
        for (int i = 0; i < length; i++)
        {
            this->str[i] = toupper(this->str[i]);
        }
    }
};
///////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Rus");
    String s1 = "“ише едешь Ц дальше будешь.";
    cout << "s1 = ";
    s1.display();
    s1.upit();
    s1.display();
    system("pause");
    return 0;
}
