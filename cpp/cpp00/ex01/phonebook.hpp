#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>

class Phonebook
{
private:
	Contact	contacts[8];
	int		size;
	int		start_idx;
public:
	Phonebook();
	void	start_phonebook();
	void	add_new_contact();
	void	search_contacts();
};

#endif