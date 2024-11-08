#include "Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "Cat: created - default constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: deleted" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal() {
	this->type = cat.type;
	std::cout << "Cat: created - copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}