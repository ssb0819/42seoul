#include "Cat.hpp"

Cat::Cat() {
	setType("Cat");
	brain = new Brain();
	std::cout << "Cat: created - default constructor" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat: deleted" << std::endl;
}

Cat::Cat(const Cat& cat) : AAnimal() {
	this->type = cat.type;
	brain = new Brain(*(cat.brain));
	std::cout << "Cat: created - copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	delete (this->brain);
	this->brain = new Brain(*cat.brain);
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}

const Brain* Cat::getBrain() const {
	return brain;
}