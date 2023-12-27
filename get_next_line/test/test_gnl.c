#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_read_txt(char *file_name, int repeat_num);
void	check_leak(void);

int	main(void)
{
	atexit(check_leak);
	test_read_txt("./test_one_line.txt", 2);
	test_read_txt("./test_two_line.txt", 3);
	test_read_txt("./test_only_nl.txt", 2);
}

void   check_leak(void)
{
		system("leaks a.out");
}

void	test_read_txt(char *file_name, int repeat_num)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("open error\n");
	else
	{
		printf("==== file name : %s ====\n", file_name);
		while (i < repeat_num)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
			i++;
		}
		printf("\n======== end =======");
	}
}
