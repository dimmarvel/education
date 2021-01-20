#ifndef MENU_H_
#define MENU_H_

#include "Precompiled.h"
#include "FileAnalyst.h"

enum mode
{
	SYMB = 0,
	PARAGRAPH = 1,
	END = 9
};

class Menu
{
private:
	FileAnalyst _fAnalyst;
private:
	void show_info();
	int mode_check(mode m);

public:
	Menu(const std::string& path);
	void change_path(const std::string& path);
	void menu();
};



#endif /* MENU_H_ */
