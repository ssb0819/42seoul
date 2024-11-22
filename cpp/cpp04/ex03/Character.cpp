#include "Character.hpp"

const size_t	Character::slot_size = 4;

Character::Character(const std::string name) : name(name) {
	for (size_t i = 0; i < slot_size; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.getName()) {
	for (size_t i = 0; i < slot_size; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character::~Character() {
	for (size_t i = 0; i < slot_size; i++)
		delete inventory[i];
}

Character& Character::operator=(const Character& other) {
	if (this == &other)
		return *this;
	this->name = other.getName();
	for (size_t i = 0; i < slot_size; i++)
	{
		if (inventory[i])
			delete inventory[i];
			
		if (other.inventory[i]) {
			inventory[i] = other.inventory[i]->clone();
			std::cout << other.inventory[i]->getType() << " is cloned by =operator" << std::endl;
		}
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

	for (size_t i = 0; i < slot_size; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Character: the inventory is full" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || (const size_t)idx >= slot_size)
		return;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || (const size_t)idx >= slot_size)
		return;
	if (inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "Character: the inventory is empty" << std::endl;
}

AMateria*	Character::getMateria(int idx) {
	if (idx < 0 || (const size_t)idx >= slot_size)
		return NULL;
	return inventory[idx];
}