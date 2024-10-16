#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(
	std::string &f_name, 
	std::string &l_name, 
	std::string &n_name, 
	std::string &ph_num, 
	std::string &d_secret
	)
	: first_name(f_name), 
	last_name(l_name), 
	nickname(n_name), 
	phone_num(ph_num), 
	darkest_secret(d_secret) {}

void Contact::print_all_col() const
{
	std::cout << "First name : " << first_name << std::endl;
	std::cout << "Last name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone number : " << phone_num << std::endl;
	std::cout << "Darkest secret : " << darkest_secret << std::endl;
}

void Contact::print_4_col() const
{
	print_truncated(first_name, 10);
	std::cout << '|';
	print_truncated(last_name, 10);
	std::cout << '|';
	print_truncated(nickname, 10);
	std::cout << std::endl;
}

void Contact::print_truncated(std::string str, int length) const
{
	size_t	str_len;

	str_len = str.size();
	if (str_len > length)
	{
		std::cout.write(str.c_str(), 9) << '.';
	}
	else
	{
		std::cout.width(10);
		std::cout << str;
	}
}
