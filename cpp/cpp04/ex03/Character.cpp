#include "Character.hpp"
#include "AMateria.hpp"

const int	Character::slot_size = 4;

Character::Character(const std::string name) : name(name) {
	for (size_t i = 0; i < slot_size; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.getName()) {
	for (size_t i = 0; i < slot_size; i++)
		inventory[i] = other.inventory[i];
}

Character::~Character() {
	for (size_t i = 0; i < slot_size; i++)
	{
		if (inventory[i])
			delete inventory[i];
		else
			return;
	}
}

Character& Character::operator=(const Character& other) {
	for (size_t i = 0; i < slot_size; i++)
	{
		if (inventory[i])
			delete inventory[i];
			
		if (other.inventory[i])
			inventory[i] = other.inventory[i];
		else
			inventory[i] = NULL;
	}
	return *this;
}

const std::string& Character::getName() const {
	return name;
}

void	Character::equip(AMateria* m) {
	if (!m)
		return;

	size_t	idx = 0;

	while (idx < slot_size && inventory[idx])
		idx++;
	if (idx < slot_size)
		inventory[idx] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > slot_size)
		return;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > slot_size)
		return;
	inventory[idx]->use(target);
}

AMateria*	Character::getMateria(int idx) {
	if (idx < 0 || idx > slot_size)
		return NULL;
	return inventory[idx];
}