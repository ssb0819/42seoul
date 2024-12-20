#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
public:
	Character(const std::string name);
	Character(const Character& other);
	virtual	~Character();
	Character&	operator=(const Character& other);

	virtual const std::string& getName() const;
	virtual	void	equip(AMateria* m);
	virtual	void	unequip(int idx);
	virtual	void	use(int idx, ICharacter& target);
	AMateria*		getMateria(int idx);
private:
	AMateria*	inventory[4];
	std::string	name;
	static const size_t	slot_size;
	
	Character();
};

#endif
