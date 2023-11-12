#include "../libft.h"
#include "test_libft.h"

t_list	*lst;

int	main(void)
{
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstadd_back();
	test_lstlast();
	test_lstmap();
	test_lstclear();
}

void	test_lstnew()
{
	char	*content = "lstnew: OK\n";

	lst = ft_lstnew(content);
}

void	test_lstadd_front()
{
	char	*content = "lstadd_front: OK\n";
	void	(*f)(void *);

	ft_lstadd_front(&lst, ft_lstnew(content));
	f = print_content;
	ft_lstiter(lst, f);
}

void	test_lstsize()
{
	int	lstsize;

	lstsize = ft_lstsize(lst);
	if (lstsize == 2)
		printf("lstsize: OK\n");
	else
	{
		printf("lstsize: KO\n");
		printf("\texpected: 2 but result:%d\n", lstsize);
	}
}

void	test_lstadd_back()
{
	char	*content = "lstlast: OK\nlstadd_back: OK\n";

	ft_lstadd_back(&lst, ft_lstnew(content));
}

void	test_lstlast()
{
	t_list	*last;
	char	*content;

	last = ft_lstlast(lst);
	content = (char *)(last->content);
	printf("%s", content);
}

void	test_lstmap()
{
	t_list	*newlst;
	void	*(*change)(void *content);
	void	(*del)(void *content);
	void	(*print)(void *content);

	change = change_content;
	del = delete_content;
	print = print_content;
	newlst = ft_lstmap(lst, change, del);
	printf("%d\n", ft_lstsize(newlst));
	if (ft_lstsize(lst) == ft_lstsize(newlst))
	{
		printf("lstmap: ");
		ft_lstiter(newlst, print);
		printf("OK\n");
	}
	else
		printf("lstmap: KO\n");
}

void	test_lstclear()
{
	void	(*del)(void *content);
	void	(*print)(void *content);

	del = delete_content;
	print = print_content;
	ft_lstclear(&lst, del);
	if (lst == NULL)
		printf("lstclear: OK\n");
	else
	{
		printf("lstclear: KO\n");
		ft_lstiter(lst, print);
	}
}

void	print_content(void *content)
{
	printf("%s", (char *)content);
}

void	*change_content(void *content)
{
	char	*nulstr;

	nulstr = (char *)calloc(1, 1);
	*nulstr = 0;
	return (nulstr);
}

void	delete_content(void *content)
{
	content = NULL;
}
