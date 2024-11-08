#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal: created - default constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: deleted" << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.type) {
	std::cout << "Animal: created - copy constructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal) {
	this->type = animal.type;
	return *this;
}

void	Animal::setType(const std::string type) {
	this->type = type;
}

const std::string& Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {}