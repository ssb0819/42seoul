#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& materia);
	AMateria&	operator=(const AMateria& materia);
	AMateria(const std::string& type);

	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
