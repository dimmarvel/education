#include "FileAnalyst.h"

FileAnalyst::FileAnalyst(const std::string& path)
	: _fstr(path),
	  _buffer(4096u),
	  _ofset(0u)
{
	if(!_fstr.is_open())
		throw std::runtime_error("File not open.");
	else
		std::cout << "File open." << std::endl;
	read_data_to_buffer();
};

void FileAnalyst::read_data_to_buffer()
{
	do
	{
	    _buffer[_ofset++] = _fstr.get();
	} while(!_fstr.eof());
}

std::size_t FileAnalyst::symb_count()
{
	//TODO...
	return 1u;
}

std::size_t FileAnalyst::paragraph_count()
{
	//TODO...
	return 1u;
}

void FileAnalyst::show_buffer()
{
	for(std::size_t i = 0; i < _ofset - 1; i ++)
		std::cout << _buffer[i];
}
