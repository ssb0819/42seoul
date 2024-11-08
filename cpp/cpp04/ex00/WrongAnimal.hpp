#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
	void	setType(const std::string type);
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& animal);
	WrongAnimal&	operator=(const WrongAnimal& animal);

	const std::string&	getType() const;
	void	makeSound() const;
};

#endif
