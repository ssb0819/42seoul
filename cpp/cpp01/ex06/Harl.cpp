#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-\
specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info(){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put \
enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for \
years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(){
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level){
	const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	for (i = 0; i < 4; i++){
		if (level.compare(levels[i]) == 0)
			break ;
	}
	
	switch (i){
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;	
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}