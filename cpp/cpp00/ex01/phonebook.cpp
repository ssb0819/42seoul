#include "phonebook.hpp"

int	main() {
	Phonebook phonebook;
	phonebook.start_phonebook();
}

Phonebook::Phonebook() {
    size = 0;
	start_idx = 0;
}

void Phonebook::start_phonebook() {
	std::string input;

	while (1)
	{
		std::cout << "Enter command. [ADD, SEARCH, EXIT]" << std::endl << "> ";
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
			add_new_contact();
		else if (input.compare("SEARCH") == 0)
			search_contacts();
		else if (input.compare("EXIT") == 0)
			break;
	}
}

void Phonebook::add_new_contact() {
	Contact &cur = contacts[(start_idx + size) % 8];
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_num;
	std::string darkest_secret;

	get_field("First name: ", first_name);
	get_field("Last name: ", last_name);
	get_field("Nickname: ", nickname);
	get_field("Phone number: ", phone_num);
	get_field("Darkest secret: ", darkest_secret);
	
	cur.set_first_name(first_name);
	cur.set_last_name(last_name);
	cur.set_nickname(nickname);
	cur.set_phone_num(phone_num);
	cur.set_darkest_secret(darkest_secret);

	if (size < 8)
		size++;
	else
		start_idx = (start_idx + 1) % 8;
	std::cout << "Saved a new contact." << std::endl;
}

void Phonebook::get_field(std::string prompt, std::string &field) {
	while (field.size() == 0)
	{
		std::cout << prompt;
		getline(std::cin, field);
	}
}

void Phonebook::search_contacts() {
	Contact	*contact;
	int idx;

	idx = 0;
	if (size == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
    for (int i = 0; i < size; i++)
	{
		contact = &contacts[(start_idx + i) % 8];
		std::cout << "         " << i + 1 << '|';
		print_column(contact->get_first_name());
		std::cout << '|';
		print_column(contact->get_last_name());
		std::cout << '|';
		print_column(contact->get_nickname());
		std::cout << std::endl;
	}
	while (1)
	{
		std::cout << "Enter index of the entry to display." << std::endl;
		std::cin >> idx;
		if (std::cin.fail())
        	std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (idx > 0 && idx <= size)
			break;
	}
	contact = &contacts[(start_idx + idx - 1) % 8];
	std::cout << "First name:\t" << contact->get_first_name() << std::endl; 
	std::cout << "Last name:\t" << contact->get_last_name() << std::endl; 
	std::cout << "Nickname:\t" << contact->get_nickname() << std::endl;
	std::cout << "Phone number:\t" << contact->get_phone_num() << std::endl;
	std::cout << "Darkest secret:\t" << contact->get_darkest_secret() << std::endl;
}

void Phonebook::print_column(std::string str) {
	if (str.size() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) << '.';
}