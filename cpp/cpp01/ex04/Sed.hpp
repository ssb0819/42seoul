#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

class Sed
{
private:
	std::string	oldstr;
	std::string	newstr;
	std::string	filename;
public:
	Sed();
	~Sed();
	void	set_oldstr(const std::string str);
	void	set_newstr(const std::string str);
	void	set_filename(const std::string filename);
	void	replace() const;
};

#endif
