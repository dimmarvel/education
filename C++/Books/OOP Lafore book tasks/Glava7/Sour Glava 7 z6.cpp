// cardaray.cpp
// класс игральных карт
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card
{
private:
    int number;
    Suit suit;

public:
    card() // конструктор
    {
    }
    void set(int n, Suit s) // установка значения
    {
        suit = s;
        number = n;
    }
    void display(); // показ карты
};
/////////////////////////////////////////////////////////////
void card::display()
{
    if (number >= 2 && number <= 10)
        cout << number;
    else
    {
        switch (number)
        {
        case jack:
            cout << 'J';
            break;
        case queen:
            cout << 'Q';
            break;
        case king:
            cout << 'K';
            break;
        case ace:
            cout << 'A';
            break;
        }
    }
    switch (suit)
    {
    case clubs:
        cout << static_cast<char>(5);
        break;
    case diamonds:
        cout << static_cast<char>(4);
        break;
    case hearts:
        cout << static_cast<char>(3);
        break;
    case spades:
        cout << static_cast<char>(6);
        break;
    }
}
/////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Rus");
    card deck2[4][13];
    int j;
    cout << endl;
    for (j = 0; j < 4; j++) // создаем упорядоченную колоду карт
    {
        for (int i = 0; i < 13; i++)
        {
            int num = (i % 13) + 2;
            Suit su = Suit(i / 13);
            deck2[j][i].set(num, su);
        }
    }
    cout << endl;
    srand(time(NULL));
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            int k = rand() % 13;     // выбираем случайную карту
            card temp = deck2[j][i]; // и меняем ее с текущей
            deck2[j][i] = deck2[j][k];
            deck2[j][k] = temp;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        cout << "Deck - " << j + 1;
        cout << endl;
        for (int i = 0; i < 13; i++)
        {
            deck2[j][i].display();
            cout << " ";
        }
        cout << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}
