#include "AAnimal.hpp"

AAnimal::AAnimal() {}

AAnimal::~AAnimal() {
	std::cout << "AAnimal: deleted" << std::endl;
}

AAnimal::AAnimal(const AAnimal& animal) : type(animal.type) {
	std::cout << "AAnimal: created - copy constructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& animal) {
	this->type = animal.type;
	return *this;
}

void	AAnimal::setType(const std::string type) {
	this->type = type;
}

const std::string& AAnimal::getType() const {
	return type;
}
