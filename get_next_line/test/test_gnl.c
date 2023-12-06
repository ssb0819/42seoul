#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_read_txt();

int	main(void)
{
	test_read_txt();
}

void	test_read_txt()
{
	int		fd;
	char	*str;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open error\n");
	}
	else
	{
		str = get_next_line(fd);
		//read(fd, str, 5);
		printf("%s\n", str);
		close(fd);
	}
}
