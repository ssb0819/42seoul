#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "\n===== test start =====\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	std::cout << "type: " << i->getType() << std::endl;
	std::cout << "type: " << j->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n===== Wrong class test =====\n" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	
	std::cout << "type: " << i2->getType() << std::endl;
	i2->makeSound();
	meta2->makeSound();

	std::cout << "\n===== test end =====\n" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete meta2;
	delete i2;

	return 0;
}