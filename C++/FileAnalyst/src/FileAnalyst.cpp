#include "FileAnalyst.h"

//-------Constructor:
FileAnalyst::FileAnalyst(const std::string& path)
	: _fstr(path),
	  _words_cache(0u),
	  _ofset(0u),
	  _buffer(4096u)
{
	if(!_fstr.is_open())
		throw std::runtime_error("File not open.");
	else
		std::cout << "File open." << std::endl;
	read_data_to_buffer();
};

//--------Private:
void FileAnalyst::read_data_to_buffer()
{
	do
	{
	    _buffer[_ofset++] = _fstr.get();
	} while(!_fstr.eof());
}

std::vector<info> FileAnalyst::get_vector_words()
{
	std::vector<info> v;
	info inf;
	std::size_t curr_pos = 0;
	std::size_t curr_paragr = 0;
	std::string temp;
	inf.flush();

	//if cache empty then find words and add to cache, else return cache
	if(_words_cache.empty())
	{
		for(std::size_t i = 0; i < _ofset - 1; i ++)
		{
			if(_buffer[i] != '\n' && _buffer[i] != ' ')
			{
				temp += _buffer[i];
				curr_pos++;
			}
			else
			{
				if(!temp.empty())
				{
					inf._word = temp;
					inf._pos = curr_pos - (int)temp.size();
					inf._paragraph = curr_paragr;

					v.push_back(inf);
					temp.clear();
				}

				if(_buffer[i] == ' ')
					curr_pos++;

				if(_buffer[i] == '\n')
				{
					curr_pos = 0;
					curr_paragr++;
				}

			}
		}
		_words_cache = v;
	}
	else
	{
		return _words_cache;
	}

	return v;
}

//--------Public:
std::size_t FileAnalyst::symb_count()
{
	return _ofset;
}

std::size_t FileAnalyst::paragraph_count()
{
	std::size_t paragraphs = 0u;

	for(std::size_t i = 0; i < _ofset - 1; i ++)
		if(_buffer[i] == '\n')
			paragraphs++;

	return paragraphs;
}

std::size_t FileAnalyst::words_count()
{
	std::size_t count = 0u;

	for(std::size_t i = 0; i < _ofset - 1; i ++)
		if((_buffer[i] == ' ' && _buffer[i+1] != ' ')
				|| (_buffer[i+1] == '\n'  || _buffer[i+1] == EOF))
			count++;

	return count;
}

std::size_t FileAnalyst::spec_char_count(int ch)
{
	std::size_t count = 0u;
	for(std::size_t i = 0; i < _ofset - 1; i ++)
		if(_buffer[i] == ch)
			count++;
	return count;
}

std::unique_ptr<info> FileAnalyst::find_word(std::string w)
{
	std::unique_ptr<info> inf;

	if(_words_cache.empty())
		_words_cache = get_vector_words();
	else
	{
		for(auto& it : _words_cache)
			if(it._word == w)
			{
				inf = std::make_unique<info>(it);
				break;
			}
	}

	return inf;
}

void FileAnalyst::show_buffer()
{
	for(std::size_t i = 0; i < _ofset - 1; i++)
		std::cout << _buffer[i];
}

void FileAnalyst::show_words_info()
{
	std::vector<info> vec = get_vector_words();
	for(const auto& it : vec)
	{
		std::cout << "Word: " << it._word << "\n"
				<< "Position: " << it._pos << "\n"
				<< "Paragraph: " << it._paragraph << std::endl;
	}
}
