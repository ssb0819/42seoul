#ifndef CONTACT_HPP
#define CONTACT_HPP

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
	void		set_first_name(std::string &str);
	void		set_last_name(std::string &str);
	void		set_nickname(std::string &str);
	void		set_phone_num(std::string &str);
	void		set_darkest_secret(std::string &str);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_num();
	std::string get_darkest_secret();
};

#endif