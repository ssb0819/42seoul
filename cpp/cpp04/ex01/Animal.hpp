#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& animal);
	Animal&	operator=(const Animal& animal);

	const std::string&	getType() const;
	virtual void	makeSound() const;
protected:
	std::string	type;
	
	void	setType(const std::string type);
};

#endif
