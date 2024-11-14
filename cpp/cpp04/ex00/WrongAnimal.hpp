#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual	~WrongAnimal();
	WrongAnimal(const WrongAnimal& animal);
	WrongAnimal&	operator=(const WrongAnimal& animal);

	const std::string&	getType() const;
	void	makeSound() const;
protected:
	std::string	type;
	
	void	setType(const std::string type);
};

#endif
