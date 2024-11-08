#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	setType("WrongCat");
	std::cout << "WrongCat: created - default constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: deleted" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal() {
	this->type = cat.type;
	std::cout << "WrongCat: created - copy constructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& cat) {
	this->type = cat.type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "meowwwww" << std::endl;
}