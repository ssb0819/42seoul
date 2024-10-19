#include "Harl.hpp"

int main(int argc, char** argv)
{
	Harl	harl;
	
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("non");
}