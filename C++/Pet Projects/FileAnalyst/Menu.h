#ifndef MENU_H_
#define MENU_H_

#include "FileAnalyst.h"
#include "Precompiled.h"
#include "Searcher.h"

enum mode
{
    INFO = 0,
    WORD = 1,
    END = 9
};

class Menu
{
private:
    FileAnalyst _fAnalyst;
    Searcher* _searcher;

private:
    void show_info();
    int mode_check(mode m);

public:
    Menu(std::vector<std::string>& path);
    ~Menu() { delete _searcher; };
    void change_path(const std::string& path);
    void menu();
};

#endif /* MENU_H_ */
