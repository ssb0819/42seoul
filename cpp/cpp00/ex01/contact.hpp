#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_num;
	std::string	darkest_secret;
public:
	Contact();
	Contact(
		std::string	&f_name,
		std::string	&l_name,
		std::string	&n_name,
		std::string	&ph_num,
		std::string	&d_secret
	);
	void	print_all_col() const;
	void	print_4_col() const;
};

#endif