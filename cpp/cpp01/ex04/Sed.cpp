#include "Sed.hpp"

Sed::Sed(const char* oldstr, const char* newstr, const char* filename) \
	: oldstr(oldstr), newstr(newstr), filename(filename)
{
	if (this->oldstr.length() == 0)
		throw std::invalid_argument("Error: old string must not be empty");	
}

Sed::~Sed()
{}

void	Sed::replace() const
{
	std::ifstream	infile;
	std::ofstream	outfile;
	const size_t	oldstr_len = oldstr.length();

	infile.open(filename.c_str());
	if (infile.fail())
		throw std::runtime_error("Error: file open error: " + filename);

	const std::string	outfilename = filename + ".replace";
	outfile.open(outfilename.c_str());
	if (outfile.fail())
		throw std::runtime_error("Error: file open error: " + outfilename);

	std::string	read_line;
	while (true)
	{
		std::getline(infile, read_line);

		size_t	found;
		while (true)
		{
			found = read_line.find(oldstr);
			if (found != std::string::npos)
			{
				outfile.write(read_line.c_str(), found);
				outfile << newstr;
				read_line = read_line.substr(found + oldstr_len);
			}
			else
			{
				outfile << read_line;
				break ;
			}
		}
		if (infile.eof())
			break;
		outfile << std::endl;	
	}
	infile.close();
	outfile.close();	
}