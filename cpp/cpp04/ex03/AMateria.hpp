#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& materia);
	virtual	~AMateria();
	AMateria&	operator=(const AMateria& materia);

	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
protected:
	std::string	type;
private:
	AMateria();
};

#endif
