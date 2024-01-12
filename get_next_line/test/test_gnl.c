#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_read_txt(char *file_name, int repeat_num);
void	test_read_error(char *file_name, int repeat_num);
void	check_leak(void);

int	main(void)
{
	//atexit(check_leak);
	//test_read_error("read_error.txt", 5);
	test_read_txt("42_with_nl", 3);

	// test_read_txt("test_one_line.txt", 2);
	// test_read_txt("giant_line.txt", 1);
	//test_read_txt("multiple_line_no_nl", 6);
	//test_read_txt("./big_line_no_nl", 1);
	// test_read_txt("./test_two_line.txt", 2);
	// test_read_txt("./test_3lines_with_nl.txt", 3);
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
	printf("\n==== file name : %s ====\n", file_name);
	if (fd == -1)
		printf("open error\n");
	else
	{
		while (i < repeat_num)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
			i++;
		}
	}
	printf("\n==== end =====================\n");
}

void	test_read_error(char *file_name, int repeat_num)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("open error");
	else
	{
		printf("\n==== file name : %s ====\n", file_name);
		str = get_next_line(fd);
		printf("1. %s", str);
		free(str);

		close(fd);

		str = get_next_line(fd);
		printf("2. %s", str);
		free(str);

		fd = open(file_name, O_RDONLY);
		if (fd == -1)
			printf("open error");
		while (i < repeat_num)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
			i++;
		}
		printf("\n==== end =====================\n");
	}
}
