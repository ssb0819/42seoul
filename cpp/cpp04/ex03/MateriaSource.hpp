#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	virtual	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& other);

	virtual	void	learnMateria(AMateria* materia);
	virtual	AMateria*	createMateria(std::string const & type);
private:
	AMateria*	materias[4];
	static const size_t	max_size;
};

#endif