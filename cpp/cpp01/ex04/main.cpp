#include "Sed.hpp"

int main(int argc, char** argv)
{
	if (argc < 4){
		std::cerr << "Error: please enter old string, new string, file name" << std::endl;
		return (1);
	}

	try{
		Sed	sed(argv[1], argv[2], argv[3]);
		sed.replace();
	}
	catch(const std::invalid_argument& e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch(const std::runtime_error& e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
}
