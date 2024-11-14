#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	brain = new Brain();
	std::cout << "Dog: created - default constructor" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog: deleted" << std::endl;
}

Dog::Dog(const Dog& dog) : AAnimal() {
	this->type = dog.type;
	brain = new Brain(*(dog.brain));
	std::cout << "Dog: created - copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog) {
	this->type = dog.type;
	delete this->brain;
	this->brain = new Brain(*dog.brain);
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}

const Brain* Dog::getBrain() const {
	return brain;
}