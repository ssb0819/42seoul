#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& ice);
	Ice&	operator=(const Ice& ice);
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
