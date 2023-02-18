#include <cstring>
#include <iostream>
using namespace std;
void reversit(char arr1[]);

int main()
{
    setlocale(LC_ALL, "Rus");
    const int MAX = 100;
    char word[MAX];
    cin.get(word, MAX);
    reversit(word);
    cout << "reverset string - " << word;
    cout << endl;
    system("Pause");
}

void reversit(char arr1[])
{
    int len = strlen(arr1);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = arr1[i];
        arr1[i] = arr1[strlen(arr1) - i - 1];
        arr1[strlen(arr1) - i - 1] = temp;
    }
}