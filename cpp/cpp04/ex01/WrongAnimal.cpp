#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "WrongAnimal: created - default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: deleted" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) : type(animal.type) {
	std::cout << "WrongAnimal: created - copy constructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& animal) {
	this->type = animal.type;
	return *this;
}

void	WrongAnimal::setType(const std::string type) {
	this->type = type;
}

const std::string& WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {}
