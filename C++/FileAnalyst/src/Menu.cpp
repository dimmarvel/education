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
			"2 - count words;\n" <<
			"3 - count specific characters;\n" <<
			"4 - find word;\n" <<
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
	else if(c == mode::WORDS)
	{
		std::cout << "Start count words...\n";
		std::cout << "All words - "
				  << _fAnalyst.words_count() << std::endl;
	}
	else if(c == mode::SPECCHAR)
	{
		char ch;
		std::cout << "Input specific character: ";
		std::cin.clear();
		std::cin >> ch;
		std::cout << "Start count specific characters...\n";
		std::cout << "All specific characters (" << ch << ") - "
				  << _fAnalyst.spec_char_count((int)ch) << std::endl;
	}
	else if(c == mode::FWORD)
	{
		std::string word;
		std::cout << "Input word: ";
		std::cin >> word;
		std::cout << "Start find word...\n";

		std::unique_ptr<info> inf = std::move(_fAnalyst.find_word(word));
		if(inf != NULL)
			std::cout << "Word info(" << inf->_paragraph << ", " << inf->_pos << ")\n";
		else
			std::cout << "Word not found." << std::endl;
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
	int c;
	show_info();

	do
	{
		std::cout << "Input: ";
		std::cin >> c;
	} while(mode_check((mode)c) != (int)mode::END);
}

