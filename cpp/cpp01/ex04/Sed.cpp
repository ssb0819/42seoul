#include "Sed.hpp"

Sed::Sed()
{}

Sed::~Sed()
{}

void	Sed::set_oldstr(const std::string str)
{
	if (str.length() == 0)
	{
		std::cout << "sed: search string must not be empty" << std::endl;
		return ;
	}
	oldstr = str;
}

void	Sed::set_newstr(const std::string str)
{
	newstr = str;
}

void	Sed::set_filename(const std::string filename)
{
	if (filename.length() == 0)
	{
		std::cout << "sed: file name must not be empty" << std::endl;
		return ;
	}
	this->filename = filename;
}

void	Sed::replace() const
{
	std::ifstream	infile;
	std::ofstream	outfile;
	const size_t	oldstr_len = oldstr.length();

	if (oldstr_len == 0)
	{
		std::cout << "sed: search string must not be empty" << std::endl;
		return ;
	}
	infile.open(filename);
	if (infile.fail())
	{
		std::cout << "sed: input file open error" << std::endl;
		return ;
	}
	std::string		outfilename = filename;
	outfile.open(outfilename.append(".replace"));
	if (outfile.fail())
	{
		std::cout << "sed: output file open error" << std::endl;
		return ;
	}

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