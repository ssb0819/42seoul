#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_mandatory();
void	test_bonus(void);
void	test_read_txt(char *file_name, int repeat_num);
void	test_read_error(char *file_name, int repeat_num);
void	check_leak(void);

int	main(void)
{
	// test_mandatory();
	test_bonus();
}

void	test_mandatory(void)
{
	atexit(check_leak);
	test_read_error("read_error.txt", 5);

	// test_read_txt("42_with_nl", 3);
	// test_read_txt("test_one_line.txt", 2);
	// test_read_txt("giant_line.txt", 1);
	// test_read_txt("multiple_line_no_nl", 6);
	// test_read_txt("./big_line_no_nl", 1);
	// test_read_txt("./test_two_line.txt", 2);
	// test_read_txt("./test_3lines_with_nl.txt", 3);
}

void	test_bonus(void)
{
	int	fd[10];

	fd[0] = open("test_3lines_with_nl.txt", O_RDONLY);
	fd[1] = open("test_one_line.txt", O_RDONLY);
	fd[2] = open("test_two_line.txt", O_RDONLY);

	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
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

void   check_leak(void)
{
	system("leaks a.out");
}