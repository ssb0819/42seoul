#include <stdio.h>

int	main(void)
{
	const char cnst_s[6]= "abcde";
	char *s = (char *)(&cnst_s);
	s[1] = 'a';

	printf("##%c##\n", cnst_s[1]);
}