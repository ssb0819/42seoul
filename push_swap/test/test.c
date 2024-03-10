#include "../push_swap.h"

void	test_list(int argc, char **argv);

int main(int argc, char **argv)
{
	test_list(argc, argv);
}

void	test_list(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return ;

	// list init test
	stack_a = lst_init();

	// list add test
	for (int i = argc - 1; i > 0; i--)
	{
		int	value;
		value = argv[i][0] - '0';
		if (!lst_addfirst(stack_a, value))
			write(1, "Error\n", 6);
	}
	printall(stack_a, "a");

	// list delete one node test
	lst_delfirst(stack_a);
	printall(stack_a, "a");

	// list delete all node test
	lst_delall(stack_a);
	printall(stack_a, "a");

}