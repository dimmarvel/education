
#ifndef FILEANALYST_H_
#define FILEANALYST_H_

#include "Precompiled.h"

class FileAnalyst
{
	std::ofstream _fstr;
public:
	explicit FileAnalyst(const std::string& path);
	std::size_t symb_count();
	std::size_t paragraph_count();
};



#endif /* FILEANALYST_H_ */
