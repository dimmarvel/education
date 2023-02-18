#include "FileAnalyst.h"

//-------Constructor:
FileAnalyst::FileAnalyst(std::vector<std::string>& path) : _data(0u), _offset(0u), _paths(path), _buffer(4096u)
{
    analyze_data();
};

//--------Private:
void FileAnalyst::read_data_to_buffer(std::string fileName)
{
    _fstr.close();
    _fstr.open(fileName);

    if (!_fstr.is_open())
        throw std::runtime_error("File not open.");
    else
        std::cout << "File open." << std::endl;

    _buffer.clear();
    _offset = 0;
    do
    {
        _buffer[_offset++] = _fstr.get();
    } while (!_fstr.eof());
}

void FileAnalyst::analyze_data()
{
    for (auto& it : _paths)
    {
        FileInfo fileInfo;
        SentInfo sentInfo;
        WordInfo wordInfo;
        int offset_word = 0;
        int sent_number = 0;
        sentInfo.flush();
        wordInfo.flush();
        fileInfo.flush();

        fileInfo._fName = it;
        read_data_to_buffer(it);

        for (std::size_t i = 0; i < _offset; i++)
        {
            if (_buffer[i] != ' ' && _buffer[i] != '\n')
            {
                if (wordInfo._word.empty())
                    wordInfo._offset = offset_word;
                sentInfo._sent += _buffer[i];
                wordInfo._word += _buffer[i];
                offset_word++;
            }
            else if (_buffer[i] == ' ')
            {
                sentInfo._sent += _buffer[i];
                wordInfo._sent = sent_number;
                sentInfo._words.push_back(wordInfo);
                wordInfo.flush();
                offset_word++;
            }
            else if (_buffer[i] == '\n')
            {
                sentInfo._sentNumber = sent_number++;
                wordInfo._sent = sentInfo._sentNumber;

                sentInfo._words.push_back(wordInfo);
                fileInfo._words.push_back(wordInfo);
                fileInfo._sents.push_back(sentInfo);

                offset_word = 0;
                sentInfo.flush();
                wordInfo.flush();
            }
        }
        _data.push_back(fileInfo);
        fileInfo.flush();
    }
}

void FileAnalyst::show_data() const
{
    for (const auto& it_data : _data)
    {
        std::cout << "File name: " << it_data._fName << std::endl;
        for (const auto& it_sent : it_data._sents)
        {
            std::cout << "Sent #" << it_sent._sentNumber << ": \"" << it_sent._sent << "\"" << std::endl;
            for (const auto& it_word : it_sent._words)
                std::cout << "{ " << it_word._word << " (Sent#" << it_word._sent << ", offset = " << it_word._offset
                          << ") }" << std::endl;
        }
    }
}

void FileAnalyst::show_buffer()
{
    for (std::size_t i = 0; i < _offset - 1; i++)
        std::cout << _buffer[i];
}
