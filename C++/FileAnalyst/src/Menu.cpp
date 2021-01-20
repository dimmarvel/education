#include "Menu.h"

Menu::Menu(const std::string& path)
	: _fAnalyst(path)
{
	menu();
};

void Menu::show_info()
{
	std::cout <<
			"Choice action:\n" <<
			"0 - count symbols;\n" <<
			"1 - count paragraphs;\n" <<
			"9 - end.\n";
}

int Menu::mode_check(mode m)
{
	int c = (int)m;
	if(c == mode::SYMB)
	{
		std::cout << "Start count symbols...\n";
		std::cout << "All symbols - "
				  << _fAnalyst.symb_count() << std::endl;
	}
	else if(c == mode::PARAGRAPH)
	{
		std::cout << "Start count paragraphs...\n";
		std::cout << "All paragraphs - "
				  << _fAnalyst.paragraph_count() << std::endl;
	}
	else if(c == mode::END)
	{
		std::cout << "End." << std::endl;
		return c;
	}
	else
	{
		std::cout << "undefind input - try more." << std::endl;
		return false;
	}
	return true;
}

void Menu::menu()
{
	show_info();
	int c;

	do
	{
		std::cout << "Input: ";
		std::cin >> c;
	}while(mode_check((mode)c) != (int)mode::END);
}

