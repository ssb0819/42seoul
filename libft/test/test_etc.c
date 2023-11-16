#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../libft.h"

void	test_unsigned()
{
	int n = -2147483648;
	unsigned int un;

	un = n;
	un = -un;
	printf("%d\n", -n);
	printf("%u\n", un);
}


void	test_casting()
{
	int i = -1;
	unsigned char uc = (unsigned char)i;
	//uc += 1;
	char * s = (char *)(&i);
	int j = uc;
	printf("\\x%x\n", s[0]);
}

int	main(void)
{
	char	dst[20] = "0123";
	char	src[] = "abcdef";
	size_t	n = 8;
	size_t	i = 0;

	printf("%d\n", (int)ft_strlcat(NULL, NULL, 0));
}

