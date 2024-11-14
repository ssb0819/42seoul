#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);

	void	makeSound() const;
	Brain*	getBrain() const;
private:
	Brain* brain;
};

#endif
