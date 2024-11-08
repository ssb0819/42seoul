#include "Dog.hpp"

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "Dog: created - default constructor" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: deleted" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal() {
	this->type = dog.type;
	std::cout << "Dog: created - copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	this->type = dog.type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}