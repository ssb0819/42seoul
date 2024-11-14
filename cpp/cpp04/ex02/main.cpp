#include "Cat.hpp"
#include "Dog.hpp"

void	check_leaks() {
	system("leaks -q a.out");
}

int main() {
	atexit(check_leaks);

	std::cout << "\n===== deep copy test start =====" << std::endl;

	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	
	*cat1 = *cat2;

	delete cat1;
	delete cat2;

	std::cout << "===== deep copy test end =====\n" << std::endl;


	std::cout << "==== memory leak test start ====" << std::endl;

	AAnimal	*meta[10];

	for (size_t i = 0; i < 5; i++)
		meta[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		meta[i] = new Cat();

	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
		delete meta[i];
	
	std::cout << "==== memory leak test end ====\n" << std::endl;

	// AAnimal	animal(); // compile error - pure virtual method

	return 0;
}