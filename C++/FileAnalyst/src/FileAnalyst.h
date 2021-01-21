#ifndef FILEANALYST_H_
#define FILEANALYST_H_

#include "Precompiled.h"

struct info
{
	std::size_t _pos;
	std::size_t _paragraph;
	std::string _word;
public:
	void flush() { _pos = 0; _paragraph = 0; _word.clear(); }
};

class FileAnalyst
{
	std::size_t 		_ofset;
	std::ifstream 		_fstr;
	std::vector<info> 	_words_cache;
	std::vector<char> 	_buffer;
private:
	void read_data_to_buffer();
	std::vector<info> get_vector_words();
public:
	explicit FileAnalyst(const std::string& path);
	std::size_t symb_count();
	std::size_t paragraph_count();
	std::size_t words_count();
	std::size_t spec_char_count(int ch);
	std::unique_ptr<info> find_word(std::string w);
	void show_buffer();
};

#endif /* FILEANALYST_H_ */
