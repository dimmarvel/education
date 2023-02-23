#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "Precompiled.h"

class FileAnalyst;
struct FileInfo;

class Searcher
{
public:
    Searcher() { _data.clear(); };
    Searcher(const std::vector<FileInfo>&);

    void show_data();
    void find_word(std::string word);

private:
    std::vector<FileInfo> _data;
};

#endif /* SEARCHER_H_ */
