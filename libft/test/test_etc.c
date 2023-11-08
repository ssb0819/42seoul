#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int n = -2147483648;
	unsigned int un;

	un = n;
	un = -un;
	printf("%d\n", n);
	printf("%u\n", un);
}