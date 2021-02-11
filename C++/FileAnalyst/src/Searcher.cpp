#include "Searcher.h"
#include "FileAnalyst.h"

Searcher::Searcher(const std::vector<FileInfo>& data) : _data(data) {};

void Searcher::show_data()
{
	for(const auto& it_data : _data)
	{
		std::cout << "File name: " << it_data._fName << std::endl;
		for(const auto& it_sent : it_data._sents)
		{
			std::cout << "Sent #" << it_sent._sentNumber << ": \"" << it_sent._sent
					<< "\"" << std::endl;
			for(const auto& it_word : it_sent._words)
				std::cout << "{ "  << it_word._word << " (Sent#" << it_word._sent
				<< ", offset = " << it_word._offset << ") }" << std::endl;
		}
	}
}

void Searcher::find_word(std::string word)
{
	for(const auto& it_data : _data)
	{
		bool file_name = true;
		for(const auto& it_sent : it_data._sents)
		{
			for(const auto& it_word : it_sent._words)
			{
				if(word == it_word._word)
				{
					if(file_name)
					{
						std::cout << "File name: " << it_data._fName << std::endl;
						file_name = false;
					}
					std::cout << "{ "  << it_word._word << " (Sent#" << it_word._sent
							<< ", offset = " << it_word._offset << ") }" << std::endl;
				}
			}
		}
	}
}

