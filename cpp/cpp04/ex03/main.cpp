#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

void	check_leaks() {
	system("leaks -q a.out");
}

void	my_test() {
	IMateriaSource* src = new MateriaSource();

	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice); // not learned

	ICharacter* me = new Character("me");

	AMateria* tmp0 = src->createMateria("cure");
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("ice");
	AMateria* tmp3 = src->createMateria("ice");
	AMateria* tmp4 = src->createMateria("ice");
	AMateria* tmp5 = src->createMateria("non"); // not found

	me->equip(tmp0);
	me->equip(tmp1);
	me->equip(tmp2);
	me->equip(tmp3);
	me->equip(tmp4); // not equiped

	ICharacter* bob = new Character("bob");

	me->unequip(0);
	me->unequip(10);

	me->use(0, *bob); // not printed
	me->use(1, *bob);

	bob = me;
	std::cout << "name : " << bob->getName() << std::endl;

	delete cure;
	delete ice;

	delete tmp0;
	delete tmp4;
	delete tmp5;

	delete bob;
	delete me;
	delete src;
}

int	main() {
	atexit(check_leaks);

	IMateriaSource* src = new MateriaSource();
	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << tmp->getType() << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << tmp->getType() << std::endl;

	ICharacter* bob = new Character("bob");

	std::cout << "??: " << ((Character*)me)->inventory[1]->getType() << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	delete ice;
	delete cure;

	//my_test();

	return 0;
}