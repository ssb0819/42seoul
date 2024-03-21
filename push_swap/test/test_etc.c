#include <stdio.h>

int	main(void)
{
	int	 a = -3;
	a = !a;
	printf("%d", a % 5);
}