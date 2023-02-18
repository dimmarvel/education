#ifndef FILEANALYST_H_
#define FILEANALYST_H_

#include "Precompiled.h"

struct WordInfo
{
    std::size_t _offset;
    std::size_t _sent;
    std::string _word;

public:
    void flush()
    {
        _offset = 0;
        _sent = 0;
        _word.clear();
    }
};

struct SentInfo
{
    std::string _sent;
    std::size_t _sentNumber;
    std::vector<WordInfo> _words;

public:
    void flush()
    {
        _sent.clear();
        _sentNumber = 0;
        _words.clear();
    }
};

struct FileInfo
{
    std::string _fName;
    std::vector<SentInfo> _sents;
    std::vector<WordInfo> _words;

public:
    void flush()
    {
        _sents.clear();
        _fName.clear();
        _words.clear();
    }
};

class FileAnalyst
{
    std::size_t _offset;
    std::ifstream _fstr;
    std::vector<char> _buffer;
    std::vector<FileInfo> _data;
    std::vector<std::string> _paths;

private:
    void read_data_to_buffer(std::string fileName);
    void analyze_data();

public:
    std::vector<FileInfo> get_data() { return _data; }
    explicit FileAnalyst(std::vector<std::string>&);
    std::size_t symb_count();
    std::size_t paragraph_count();
    std::size_t words_count();
    std::size_t spec_char_count(int ch);
    void show_words_info();
    void show_buffer();
    void show_data() const;
};

#endif /* FILEANALYST_H_ */
