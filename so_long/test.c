#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

//UB니까 조심하기 - 동적할당한 메모리에 지역변수 주소 넣는 것
void	set_local_var(int **p)
{
	int	arr[2];

	arr[0] = 1;
	arr[1] = 2;
	p[0] = arr;
	printf("%d || %d\n", p[0][0], p[0][1]);
}

void	alloc_test(void)
{
	int	**test;

	test = malloc(sizeof(int *) * 2);
	set_local_var(test);
	printf("%d || %d\n", test[0][0], test[0][1]);
}

int	main(void)
{
	// alloc_test();
	printf("char* %zd\n", sizeof(char *));
}
