#include "FileAnalyst.h"

FileAnalyst::FileAnalyst(const std::string& path)
	: _fstr(path)
{
	if(!_fstr.is_open())
		throw std::runtime_error("File not open.");
	else
		std::cout << "File open." << std::endl;
};


std::size_t FileAnalyst::paragraph_count()
{
	//TODO...
	return 1u;
}


std::size_t FileAnalyst::symb_count()
{
	//TODO...
	return 1u;
}
