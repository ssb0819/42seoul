#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstring>
#include <cctype>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		size;
	int		oldest_idx;
public:
	PhoneBook();
	void	add();
	void	search();
private:
	Contact		get_contact_info();
	std::string	get_user_input(const char *prompt);
	int			get_add_idx();
	bool		is_valid_info(const char *str) const;
	bool		is_blank(const char *str) const;
	bool		is_printable(const char *str) const;
};

#endif