#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*test(void *data)
{
	char	a;

	a = *(char *)data;
	write(1, "thread test : ", 15);
	write(1, &a, 1);
	return ((void *)(2));
}

int	main(void)
{
	char		a = '1';
	pthread_t	thread_t;
	int			status;

	if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
	{
		perror("thread create error:");
		return (0);
	}
	pthread_join(thread_t, (void **)&status);
	printf("\nThread End %d\n", status);
	return (1);
}
