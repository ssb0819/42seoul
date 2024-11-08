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

	std::cout << "Address of cat1's idea: " << &(cat1->getBrain()->ideas[0]) << std::endl;
	std::cout << "Address of cat2's idea: " << &(cat2->getBrain()->ideas[0]) << std::endl;
	
	*cat1 = *cat2;
	std::cout << "After deep copy" << std::endl;

	std::cout << "Address of cat1's idea: " << &(cat1->getBrain()->ideas[0]) << std::endl;
	std::cout << "Address of cat2's idea: " << &(cat2->getBrain()->ideas[0]) << std::endl;

	delete cat1;
	delete cat2;

	std::cout << "===== deep copy test end =====\n" << std::endl;


	std::cout << "==== memory leak test start ====" << std::endl;

	Animal	*meta[10];

	for (size_t i = 0; i < 5; i++)
		meta[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		meta[i] = new Cat();

	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
		delete meta[i];
	
	std::cout << "==== memory leak test end ====\n" << std::endl;

	return 0;
}