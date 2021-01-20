
#ifndef FILEANALYST_H_
#define FILEANALYST_H_

#include "Precompiled.h"

class FileAnalyst
{
	std::ifstream 		_fstr;
	std::vector<char> 	_buffer;
	std::size_t 		_ofset;
private:
	void read_data_to_buffer();
public:
	explicit FileAnalyst(const std::string& path);
	std::size_t symb_count();
	std::size_t paragraph_count();
	void show_buffer();
};



#endif /* FILEANALYST_H_ */
