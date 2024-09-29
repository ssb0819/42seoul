#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string &f_name, std::string &l_name, std::string &n_name, std::string &ph_num, std::string &d_secret)
	: first_name(f_name), last_name(l_name), nickname(n_name), phone_num(ph_num), darkest_secret(d_secret) {}

void Contact::print_all_col() const
{
	std::cout << "print_all" << std::endl;
}

void Contact::print_4_col() const
{
	std::cout << "print_4" << std::endl;
}
