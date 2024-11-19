#include "MateriaSource.hpp"

const size_t	MateriaSource::max_size = 4;

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < max_size; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (size_t i = 0; i < max_size; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}
		

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < max_size; i++) {
		delete materias[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	for (size_t i = 0; i < max_size; i++)
	{
		if (materias[i])
			delete materias[i];
			
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia) {
	if (!materia)
		return;

	size_t	idx = 0;

	while (idx < max_size && materias[idx])
		idx++;
	if (idx < max_size)
		materias[idx] = materia->clone();
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (size_t i = 0; i < max_size; i++) {
		if (materias[i]) {
			if (type.compare(materias[i]->getType()) == 0)
				return (materias[i]->clone());
		}
	}
	return (NULL);		
}