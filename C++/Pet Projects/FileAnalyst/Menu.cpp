#include "Menu.h"

Menu::Menu(std::vector<std::string>& paths) : _fAnalyst(paths)
{
    _searcher = new Searcher(_fAnalyst.get_data());
    menu();
};

void Menu::show_info()
{
    std::cout << "Choice action:\n"
              << "0 - show data;\n"
              << "1 - find word;\n"
              << "9 - end.\n";
}

int Menu::mode_check(mode m)
{
    int c = (int)m;

    if (c == mode::INFO)
    {
        _searcher->show_data();
    }
    else if (c == mode::WORD)
    {
        std::string word;
        std::cin >> word;

        _searcher->find_word(word);
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
    } while (mode_check((mode)c) != (int)mode::END);
}
