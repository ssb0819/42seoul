
#include <unistd.h>
#include "libft/libft.h"

void	print_bit(unsigned char c)
{
	int	i;
	const unsigned char bit = 1;
	char	*c_num;

	i = 7;
	c_num = ft_itoa((int)c);
	write(1, "c:", 2);
	write(1, &c, 1);
	write(1, " character number:", 18);
	write(1, c_num, ft_strlen(c_num));
	free(c_num);
	while (i >= 0)
	{
		if ((c >> i & bit) == 1)
			write(1, " 1", 2);
		else
			write(1, " 0", 2);
		i--;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	print_bit(0);
	print_bit(-1);
	print_bit(128);
	print_bit(-128);
}
