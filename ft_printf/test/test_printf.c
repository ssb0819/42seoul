#include "../ft_printf.h"
#include "test_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	test_only_format();
	test_c();
	test_s();
	test_p();
	test_i();
	test_d();
	test_u();
	test_x();
	test_X();
	test_null();
	test_nullstring();
	test_multi_param();
	//test_wrong_format();
	//test_wrong_param();
}

void	test_only_format()
{
	ft_printf("\n====ft_printf test start====\n");
}

void	test_c()
{
	char	c;
	int		len;
	int		ft_len;

	c = 'a';
	printf("\n[print char %c]\n", c);
	len = printf("printf:\t\t%c\n", c);
	ft_len = ft_printf("ft_printf:\t%c\n", c);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_s()
{
	char	*s;
	int		len;
	int		ft_len;

	s = "This is test string.";
	printf("\n[print str]\n");
	len = printf("printf:\t\t%s\n",s);
	ft_len = ft_printf("ft_printf:\t%s\n",s);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_p()
{
	char	*s;
	int		len;
	int		ft_len;

	s = "test";
	printf("\n[print pointer address]\n");
	len = printf("printf:\t\t%p\n",s);
	ft_len = ft_printf("ft_printf:\t%p\n",s);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	s = NULL;
	printf("\n[print null pointer address]\n");
	len = printf("printf:\t\t%p\n",s);
	ft_len = ft_printf("ft_printf:\t%p\n",s);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	printf("\n[print pointer long max]\n");
	len = printf("printf:\t\t%p\n", LONG_MAX);
	ft_len = ft_printf("ft_printf:\t%p\n",LONG_MAX);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	printf("\n[print pointer long min]\n");
	len = printf("printf:\t\t%p\n", LONG_MIN);
	ft_len = ft_printf("ft_printf:\t%p\n", LONG_MIN);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	printf("\n[print pointer unsigned long max]\n");
	len = printf("printf:\t\t%p\n", ULONG_MAX);
	ft_len = ft_printf("ft_printf:\t%p\n",ULONG_MAX);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	printf("\n[print pointer unsigned long min]\n");
	len = printf("printf:\t\t%p\n", -ULONG_MAX);
	ft_len = ft_printf("ft_printf:\t%p\n", -ULONG_MAX);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_i()
{
	int	n;
	int	len;
	int	ft_len;

	n = 0;
	printf("\n[print zero]\n");
	len = printf("printf:\t\t%i\n", n);
	ft_len = ft_printf("ft_printf:\t%i\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = 123;
	printf("\n[print int %i]\n", n);
	len = printf("printf:\t\t%i\n", n);
	ft_len = ft_printf("ft_printf:\t%i\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = INT_MIN;
	printf("\n[print int min]\n");
	len = printf("printf:\t\t%i\n", n);
	ft_len = ft_printf("ft_printf:\t%i\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
	{
		printf("return value: KO\n");
		printf("expected:%i but result:%i\n", len +2, ft_len);
	}
	
}

void	test_d()
{
	int	n;
	int	len;
	int	ft_len;

	n = INT_MAX;
	printf("\n[print int max]\n");
	len = printf("printf:\t\t%i\n", n);
	ft_len = ft_printf("ft_printf:\t%i\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_u()
{
	unsigned int	n;
	int				len;
	int				ft_len;

	n = 0;
	printf("\n[print zero]\n");
	len = printf("printf:\t\t%u\n", n);
	ft_len = ft_printf("ft_printf:\t%u\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = 4294967197;
	printf("\n[print %u]\n", n);
	len = printf("printf:\t\t%u\n", n);
	ft_len = ft_printf("ft_printf:\t%u\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = UINT_MAX;
	printf("\n[print unsigned int max]\n");
	len = printf("printf:\t\t%u\n", n);
	ft_len = ft_printf("ft_printf:\t%u\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_x()
{
	int	n;
	int	len;
	int	ft_len;


	n = -99;
	printf("\n[print hexadecimal %i]\n", n);
	len = printf("printf:\t\t%x\n", n);
	ft_len = ft_printf("ft_printf:\t%x\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = 273;
	printf("\n[print hexadecimal %i]\n", n);
	len = printf("printf:\t\t%x\n", n);
	ft_len = ft_printf("ft_printf:\t%x\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

}

void	test_X()
{
	int	n;
	int	len;
	int	ft_len;

	n = -15;
	printf("\n[print hexadecimal %i]\n", n);
	len = printf("printf:\t\t%X\n", n);
	ft_len = ft_printf("ft_printf:\t%X\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	n = -99;
	printf("\n[print hexadecimal %i]\n", n);
	len = printf("printf:\t\t%X\n", n);
	ft_len = ft_printf("ft_printf:\t%X\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");


	n = 12345;
	printf("\n[print hexadecimal %i]\n", n);
	len = printf("printf:\t\t%X\n", n);
	ft_len = ft_printf("ft_printf:\t%X\n", n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");


}

void	test_null()
{
	char*	s;
	int		len;
	int		ft_len;

	s = (void *)0;
	printf("\n[print null test]\n");
	len = printf("printf:\t\t%s\n", s);
	ft_len = ft_printf("ft_printf:\t%s\n", s);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
	{
		printf("return value: KO\n");
		printf("expected:%i but result:%i\n", len +2, ft_len);
	}


}

void	test_nullstring()
{
	char*	s;
	int		len;
	int		ft_len;

	s = "";
	printf("\n[print null string test]\n");
	len = printf("printf:\t\t%s\n", s);
	ft_len = ft_printf("ft_printf:\t%s\n", s);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

}

void	test_multi_param()
{
	char			*s;
	int				n;
	unsigned int	un;
	int				len;
	int				ft_len;

	s = "test";
	n = -123;
	un = 123;
	printf("\n[print multiple parameters test]\n");
	len = printf("printf:\t\t%s %i %u %p %x\n", s, n, un, s, n);
	ft_len = ft_printf("ft_printf:\t%s %i %u %p %x\n", s, n, un, s, n);
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

/*
void	test_wrong_format()
{
	int	printf_len;
	int	ft_printf_len;
	int	len;
	int	ft_len;

	printf("\n[print wrong format test]\n");
	printf_len = printf("printf:\t\t%z\n", "test");
	ft_printf_len = ft_printf("ft_printf:\t%z\n", "test");
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}

void	test_wrong_param()
{
	int	printf_len;
	int	ft_printf_len;
	int	len;
	int	ft_len;

	printf("\n[print too many params test]\n");
	printf_len = printf("printf:\t\t%s\n", "one", "two", "three");
	ft_printf_len = ft_printf("ft_printf:\t%s\n", "one", "two", "three");
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");

	printf("\n[print too less params test]\n");
	printf_len = printf("printf:\t\t%s, %s\n", "one");
	ft_printf_len = ft_printf("ft_printf:\t%s, %s\n", "one");
	if (len == ft_len - 2)
		printf("return value: OK\n");
	else
		printf("return value: KO\n");
}
*/