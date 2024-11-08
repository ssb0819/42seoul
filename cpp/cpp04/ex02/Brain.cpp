#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: created - default constructor" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain: deleted" << std::endl;
}

Brain::Brain(const Brain& brain) {
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain: created - copy constructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& brain) {
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return *this;
}