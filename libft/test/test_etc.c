#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int	main(void)
{
	char	*s;
	char	dst[3];
	char	src[] = "ab";

	s = memcpy(NULL, NULL, 3);
	printf("%s\n", s);
}

void	test_unsigned()
{
	int n = -2147483648;
	unsigned int un;

	un = n;
	un = -un;
	printf("%d\n", n);
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
