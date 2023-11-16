#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%d\n", BUFSIZ);
	printf("%lu\n", sizeof(char *));
	printf("%x\n", 15);
}