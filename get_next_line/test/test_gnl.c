#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_mandatory();
void	test_bonus(void);
void	test_read_txt(char *file_name, int repeat_num);
void	test_read_error(char *file_name);
void	check_leak(void);

int	main(void)
{
	test_mandatory();
	test_bonus();
}

void	test_mandatory(void)
{
	atexit(check_leak);
	test_read_txt("txt_files/1line.txt", 1);
	test_read_txt("txt_files/2lines.txt", 2);
	test_read_txt("txt_files/3lines_with_nl.txt", 3);
	test_read_txt("txt_files/only_nl.txt", 2);
	test_read_error("txt_files/read_error.txt");
}

void	test_bonus(void)
{
	int		fd[2];
	char	*s;

	fd[0] = open("txt_files/2lines.txt", O_RDONLY);
	fd[1] = open("txt_files/3lines_with_nl.txt", O_RDONLY);

	printf("\n==== multiple files ====\n");
	s = get_next_line(fd[0]);
	printf("%s", s);
	free(s);
	s = get_next_line(fd[1]);
	printf("%s", s);
	free(s);
	s = get_next_line(fd[0]);
	printf("%s", s);
	free(s);
	s = get_next_line(fd[1]);
	printf("%s", s);
	free(s);
	printf("\n==== end ====\n");
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

void	test_read_error(char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("open error");
	else
	{
		printf("\n==== file name : %s ====\n", file_name);

		// 첫번째 gnl 호출
		str = get_next_line(fd);
		printf("1-%s", str);
		free(str);

		// 파일 close 후 gnl 호출
		close(fd);
		str = get_next_line(fd);
		printf("2-%s", str);
		free(str);

		// 파일 새로 open 후 gnl 호출
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
			printf("open error");
		str = get_next_line(fd);
		printf("1-%s", str);
		free(str);

		printf("\n==== end =====================\n");
	}
}

void   check_leak(void)
{
	system("leaks a.out");
}