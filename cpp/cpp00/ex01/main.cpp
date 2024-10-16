#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	cmd;
	char		input[7];

	while (true)
	{
		std::cout << "Enter command. [ADD, SEARCH, EXIT]\n> ";

		if (!std::cin.getline(input, 7))
		{
			if (std::cin.eof()) 
			{
                std::cout << "EOF reached. Exiting the program." << std::endl;
                break;
            }
			else 
			{
                std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
		}

		cmd = input;

		if (cmd.compare("ADD") == 0)
			phonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search();
		else if (cmd.compare("EXIT") == 0)
			break;
	}
}
