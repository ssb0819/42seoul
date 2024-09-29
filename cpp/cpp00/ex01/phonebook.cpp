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
	
	new_contact = get_contact_info();
	idx = get_add_idx();
	contacts[idx] = new_contact;

	if (size < 8)
		size++;
	else
		oldest_idx = ++oldest_idx % 8;
}

void	PhoneBook::search()
{
	std::cout << "search" << std::endl;
}

Contact	PhoneBook::get_contact_info()
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

std::string	PhoneBook::get_user_input(const char *prompt)
{
	char		input[51];

	while (true)
	{
		std::cout << "Enter " << prompt << " within 50 characters." << std::endl;

		if (!std::cin.getline(input, 51))
		{
			if (std::cin.eof()) 
			{
				std::cout << "EOF reached. Exiting the program." << std::endl;
				break;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
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

int	PhoneBook::get_add_idx()
{
	if (size == 0)
		return (0);
	else if (size < 8)
		return (size);
	else
		return (oldest_idx);
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