#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	str[3];

	read(0, str, 3);
	write(1, str, 3);
}
