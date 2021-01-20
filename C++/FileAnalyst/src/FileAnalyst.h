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
	std::vector<std::string> get_vector_words();
public:
	explicit FileAnalyst(const std::string& path);
	std::size_t symb_count();
	std::size_t paragraph_count();
	std::size_t words_count();
	std::size_t spec_char_count(int ch);
	void show_buffer();
};

#endif /* FILEANALYST_H_ */
