#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
public:
	virtual ~AAnimal();
	AAnimal(const AAnimal& animal);
	AAnimal&	operator=(const AAnimal& animal);

	const std::string&	getType() const;
	virtual void	makeSound() const = 0;
protected:
	std::string	type;
	void	setType(const std::string type);
	AAnimal();
};

#endif