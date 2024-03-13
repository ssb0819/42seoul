#include "../push_swap.h"

t_list	*test_list(int argc, char **argv);
void	test_operation(t_list *stack_a, t_list *stack_b);

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = test_list(argc, argv);
	stack_b = lst_init();
	test_operation(stack_a, stack_b);
}

t_list	*test_list(int argc, char **argv)
{
	t_list	*stack_a;
	t_node	*node;

	if (argc < 2)
		return (void *)0;

	write(1, "\n----- list test -----\n", 23);

	// test - list init
	stack_a = lst_init();

	// test - list add
	for (int i = argc - 1; i > 0; i--)
	{
		int	value;
		value = argv[i][0] - '0';
		lst_addfirst(stack_a, lst_newnode(value));
	}
	printall(stack_a, "a");

	// test - list delete one node
	node = lst_delfirst(stack_a);
	write(1, "deleted -", 9);
	node->value += '0';
	write(1, &(node->value), 1);
	write(1, "\n", 1);
	printall(stack_a, "a");
	free(node);
	node = (void *)0;

	// test - list delete all node
	lst_del_allnode(stack_a);
	printall(stack_a, "a");

	// test - list add again
	for (int i = argc - 1; i > 0; i--)
	{
		int	value;
		value = argv[i][0] - '0';
		lst_addfirst(stack_a, lst_newnode(value));
	}
	printall(stack_a, "a");

	return (stack_a);
}

 void	test_operation(t_list *stack_a, t_list *stack_b)
 {
	write(1, "\n----- operation test -----\n", 28);

	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(SA, stack_a, stack_b);
	write(1, "sa\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(PB, stack_a, stack_b);
	write(1, "pb\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(PB, stack_a, stack_b);
	write(1, "pb\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RA, stack_a, stack_b);
	write(1, "ra\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RB, stack_a, stack_b);
	write(1, "rb\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RR, stack_a, stack_b);
	write(1, "rr\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RRA, stack_a, stack_b);
	write(1, "rra\n", 4);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RRB, stack_a, stack_b);
	write(1, "rrb\n", 4);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(RRR, stack_a, stack_b);
	write(1, "rrr\n", 4);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(SB, stack_a, stack_b);
	write(1, "sb\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(SS, stack_a, stack_b);
	write(1, "ss\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");

	execute_operation(PA, stack_a, stack_b);
	write(1, "pa\n", 3);
	printall(stack_a, "a");
	printall(stack_b, "b");
 }