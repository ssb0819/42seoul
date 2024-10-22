#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class Sed
{
private:
	std::string	oldstr;
	std::string	newstr;
	std::string	filename;
public:
	Sed(const char* oldstr, const char* newstr, const char* filename);
	~Sed();
	void	replace() const;
};

#endif
