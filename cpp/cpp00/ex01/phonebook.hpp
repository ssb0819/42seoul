#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Phonebook
{
private:
	int		size;
	int		start_idx;
	Contact	contacts[8];
	void	get_field(std::string prompt, std::string &field);
	void	print_column(std::string str);
public:
	Phonebook();
	void	start_phonebook();
	void	add_new_contact();
	void	search_contacts();
};

#endif