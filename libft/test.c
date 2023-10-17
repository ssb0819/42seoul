#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ft_isalpha.h"
#include "ft_isdigit.h"
#include "ft_isalnum.h"
#include "ft_isascii.h"
#include "ft_isprint.h"
#include "ft_strlen.h"
#include "ft_memset.h"

void	test_isalpha()
{
	int	c = 'a';

	if (ft_isalpha(c) == isalpha(c))
		printf("isalpha: OK");
	else
	{
		printf("isalpha: KO");
		printf("\texpected: %d but result: %d", isalpha(c), ft_isalpha(c));
	}
	printf("\n");
}

void	test_isdigit()
{
	int	c = '5';

	if (ft_isdigit(c) == isdigit(c))
		printf("isdigit: OK");
	else
	{
		printf("isdigit: KO");
		printf("\texpected: %d but result: %d", isdigit(c), ft_isdigit(c));
	}
	printf("\n");
}

void	test_isalnum()
{
	int	c = '5';

	if (ft_isalnum(c) == isalnum(c))
		printf("isalnum: OK");
	else
	{
		printf("isalnum: KO");
		printf("\texpected: %d but result: %d", isalnum(c), ft_isalnum(c));
	}
	printf("\n");
}

void	test_isascii()
{
	int	c = 128;

	if (ft_isascii(c) == isascii(c))
		printf("isascii: OK");
	else
	{
		printf("isascii: KO\n");
		printf("\texpected: %d but result: %d", isascii(c), ft_isascii(c));
	}
	printf("\n");
}

void	test_isprint()
{
	int	c = 127;

	if (ft_isprint(c) == isprint(c))
		printf("isprint: OK");
	else
	{
		printf("isprint: KO\n");
		printf("\texpected: %d but result: %d", isprint(c), ft_isprint(c));
	}
	printf("\n");
}

void	test_strlen()
{
	const char	*s = "test";

	if (ft_strlen(s) == strlen(s))
		printf("strlen: OK");
	else
	{
		printf("strlen: KO");
		printf("\texpected: %lu but result: %lu", strlen(s), ft_strlen(s));
	}
	printf("\n");
}

void	test_memset()
{
	size_t	n = 2;
	char	s[n];
	int		c = '0';
	int		i = 0;
	char	*res;
	char	*ft_res;

	res = (char*)memset(s, c, n);
	ft_res = (char*)ft_memset(s, c, n);
	while (i < n)
	{
		if (ft_res[i] != res[i])
		{
			printf("memset: KO");
			printf("\texpected: %s but result: %s", res, ft_res);
			return;
		}
		i++;
	}
	printf("memset: OK");
	printf("\n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
}