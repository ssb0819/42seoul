#include "AMateria.hpp"

AMateria::AMateria() : type("") {};

AMateria::~AMateria() {};

AMateria::AMateria(std::string const& type) : type(type) {};

AMateria::AMateria(AMateria const& materia) {
	*this = materia;
};

AMateria&	AMateria::operator=(AMateria const& materia) {
	this->type = materia.type;
	return (*this);
};

const std::string&	AMateria::getType() const {
	return (this->type);
};

void	AMateria::use(ICharacter& /*target*/) {};