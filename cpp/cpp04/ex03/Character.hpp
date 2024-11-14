#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

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
	std::string	name;
	AMateria*	inventory[4];
	static const int	slot_size;
	
	Character();
};

#endif
