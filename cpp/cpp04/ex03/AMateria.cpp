#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {};

AMateria::AMateria(const AMateria& materia) : type(materia.type) {};

AMateria::~AMateria() {};

AMateria&	AMateria::operator=(const AMateria& materia) {
	if (this != &materia)
		this->type = materia.type;
	return *this;
};

const std::string&	AMateria::getType() const {
	return (this->type);
};

void	AMateria::use(ICharacter& /*target*/) {};