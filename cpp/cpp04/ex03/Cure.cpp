#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& cure) : AMateria(cure.type) {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& cure) {
	if (this != &cure)
		this->type = cure.type;
	return *this;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
}