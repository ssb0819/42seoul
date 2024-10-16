#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	oldest_idx = 0;
}

void	PhoneBook::add()
{
	Contact	new_contact;
	int		idx;
	
	if (size < 8)
		idx = size;
	else
		idx = oldest_idx;

	new_contact = get_contact_info();
	contacts[idx] = new_contact;

	if (size < 8)
		size++;
	else
		oldest_idx = (oldest_idx + 1) % 8;

	std::cout << "A new contact has been added." << std::endl;
}

void	PhoneBook::search()
{
	int	idx;

	if (size == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout.width(10);
		std::cout << i + 1 << '|';
		idx = (oldest_idx + i) % 8;
		contacts[idx].print_4_col();
	}
	idx = get_search_idx();
	contacts[idx].print_all_col();
}

int	PhoneBook::get_search_idx() const
{
	int	idx;

	idx = 0;
	std::cout << "Please enter a number between 1 and " << size << " to display.\n> ";
	while (true)
	{
		if (std::cin >> idx && idx > 0 && idx <= size)
		{
			std::cin.ignore(INT_MAX, '\n');
			return ((oldest_idx + idx - 1) % 8);
		}
		else
		{
			if (std::cin.eof()) 
			{
				std::cout << "EOF reached. Exiting the program." << std::endl;
				exit(EXIT_SUCCESS);
			}
			std::cout << "Invalid input. Please enter a number between 1 and " << size << ".\n> ";
        	std::cin.clear();
        	std::cin.ignore(INT_MAX, '\n');
		}
    }
}

Contact	PhoneBook::get_contact_info() const
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_num;
	std::string	darkest_secret;
	
	first_name = get_user_input("firstname");
	last_name = get_user_input("last name");
	nickname = get_user_input("nickname");
	phone_num = get_user_input("phone number");
	darkest_secret = get_user_input("darkest secret");

	Contact	contact(first_name, last_name, nickname, phone_num, darkest_secret);
	return (contact);
}

std::string	PhoneBook::get_user_input(const char *prompt) const
{
	char		input[51];

	while (true)
	{
		std::cout << "Enter " << prompt << " within 50 characters.\n> ";

		if (!std::cin.getline(input, 51))
		{
			if (std::cin.eof()) 
			{
				std::cout << "EOF reached. Exiting the program." << std::endl;
				exit(EXIT_SUCCESS);
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Input error." << std::endl;
				continue;
			}
		}

		if (is_valid_info(input))
			break;
	}
	std::string	input_str = input;
	return (input_str);
}

bool	PhoneBook::is_valid_info(const char *str) const
{
	if (!is_blank(str) && is_printable(str))
		return (true);
	else
		return (false);
}

bool PhoneBook::is_blank(const char *str) const
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool PhoneBook::is_printable(const char *str) const
{
	int	i = 0;
	
	while (str[i])
	{
		if (!isprint(str[i]))
			return (false);
		i++;
	}
	return (true);
}