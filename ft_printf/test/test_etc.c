#include <stdio.h>
#include <float.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>

void	get_bufsize()
{
	printf("%d\n", BUFSIZ);
	printf("%lu\n", sizeof(char *));
	printf("%x\n", 15);
}

void	get_min_max()
{
	printf("long min: %ld\n", LONG_MIN);
	printf("long max: %ld\n", LONG_MAX);
	printf("long long min: %lld\n", LLONG_MIN);
	printf("long long max: %lld\n", LLONG_MAX);
	printf("float min: %e\n", FLT_MIN);
	printf("float max: %e\n", FLT_MAX);
	printf("double min: %e\n", DBL_MIN);
	printf("double max: %e\n", DBL_MAX);
	printf("long double min: %Le\n", LDBL_MIN);
	printf("long double max: %Le\n", LDBL_MAX);
}

int	main(void)
{
	char	c;
	long	ptr;

	c = 'a';
	ptr = (long)(&c);
	printf("print test:%p\n", &c);
	printf("print test:%lx\n", ptr);

	printf("%lu\n", LONG_MIN);

}
