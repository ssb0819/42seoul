#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup \
burger.\nI really do!\n" << std::endl;
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
	void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < 4; i++){
		if (level.compare(levels[i]) == 0){
			(this->*func[i])();
			break ;
		}
	}
}