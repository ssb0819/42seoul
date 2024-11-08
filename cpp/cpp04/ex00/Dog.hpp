#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);

	void	makeSound() const;
};

#endif
