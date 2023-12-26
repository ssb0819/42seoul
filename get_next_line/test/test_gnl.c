#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_read_txt();
void   check_leak(void);

int	main(void)
{
	atexit(check_leak);
	test_read_txt();
}

void   check_leak(void)
{
		system("leaks a.out");
}

void	test_read_txt()
{
	int		fd;
	char	*str;

	str = (char *)calloc(50, 1);
	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
		printf("open error\n");
	else
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);

		str = get_next_line(fd);
		printf("%s", str);
		free(str);

		str = get_next_line(fd);
		printf("%s", str);
		free(str);

		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
}
