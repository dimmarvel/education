#include <iostream>
using namespace std;
class MyString;
int strLengthgth(const char *str);
int strLengthgth(const char *str) {

	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

class MyString
{
private:
	char *str;
public:
	//constructors
	MyString()
	{
		str = nullptr;
	}
	MyString(const char *str)
	{
		int length = strLengthgth(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	MyString(const MyString &other)
	{
		int length = strLengthgth(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}
	//operators
	MyString& operator = (const MyString &other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		int length = strLengthgth(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}
	MyString operator + (const MyString &other)
	{
		MyString newStr;
		int lengthOther = strLengthgth(other.str);
		int lengthThis = strLengthgth(this->str);
		newStr.str = new char[lengthOther + lengthThis + 1];
		int i = 0;
		for (; i < lengthThis; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < lengthOther; i++, j++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[lengthOther + lengthThis] = '\0';
		return newStr;
	}
	bool operator == (const MyString &other)
	{
		int lengthThis = strLengthgth(this->str);
		int lengthOther = strLengthgth(other.str);
		if (lengthThis != lengthOther)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < lengthThis; i++)
			{
				if (this->str[i] != other.str[i])
				{
					return false;
				}
			}
		}
	}
	bool operator != (const MyString &other)
	{
		return !(*this == other);
	}
	//methods
	void Getter();
	void Reverse(); // переворот строки
	void ChangeSymbol(int NumSumb, char Symb); //замена символа
	void ChangeAllSymbol(char Symbl, char ChangeSymbol); //замена символов на определенный символ
	bool isSymbl(char Symbl); //есть ли в строке символ
	int HowSymbl(char Symbl); // возвращает количество определенных символов
};
void MyString::Reverse()
{
	int length = strLengthgth(str);
	for (int i = 0, j = length-1; i < (length / 2); i++, j--)
	{
		char temp = '0';
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
void MyString::Getter()
{
	if (str != nullptr)
	{
		cout << str << endl;
	}
	else {
		cout << "Error or Empty string" << endl;
	}
}
void MyString::ChangeSymbol(int NumSymb, char Symb)
{
	int length = strLengthgth(str);
	if(NumSymb-1 < length)
	{
		str[NumSymb-1] = Symb;
	}
	else {
		cout << "NumbSymb error" << endl;
	}
}
void MyString::ChangeAllSymbol(char FindSymbl, char ChangeSymbol)
{
	int length = strLengthgth(str);
	for (int i = 0; i < length; i++)
	{
		if(str[i] == FindSymbl)
		{
			str[i] = ChangeSymbol;
		}
	}
}
bool MyString::isSymbl(char Symbl)
{
	bool check = false;
	int length = strLengthgth(str);
		for (int i = 0; i < length; i++)
		{
			if(str[i] == Symbl && check == false)
			{
				check = true;	
			}
		}
	return check;
}
int MyString::HowSymbl(char Symbl)
{
	int HowSymbl = 0;
	int length = strLengthgth(str);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == Symbl)
		{
			HowSymbl++;
		}
	}
	return HowSymbl;
}
int main()
{
	setlocale(LC_ALL,"Rus");
	MyString str("Бельчикова Кристина Степановна");
	str.Getter();
	str.Reverse();
	str.Getter();
	str.ChangeSymbol(3,'Б');
	str.Getter();
	str.ChangeAllSymbol('и','У');
	str.Getter();
	cout << str.HowSymbl('У') << endl;
	system("pause");
	return 0;

}