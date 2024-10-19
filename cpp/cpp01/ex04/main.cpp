#include "Sed.hpp"

int main(int argc, char** argv)
{
	if (argc < 4)
	{
		std::cout << "sed: please enter old string, new string, file name" << std::endl;
		exit(EXIT_SUCCESS);
	}
	Sed	sed;
	sed.set_oldstr(argv[1]);
	sed.set_newstr(argv[2]);
	sed.set_filename(argv[3]);
	sed.replace();
}
