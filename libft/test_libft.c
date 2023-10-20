#include "libft.h"
#include "test_libft.h"

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
}

void	test_isalpha()
{
	int	c = 'a';

	if (ft_isalpha(c) == isalpha(c))
		printf("isalpha: OK");
	else
	{
		printf("isalpha: KO\n");
		printf("\texpected: %d but result: %d", isalpha(c), ft_isalpha(c));
	}
	printf("\n");
}

void	test_isdigit()
{
	int	c = '5';

	if (ft_isdigit(c) == isdigit(c))
		printf("isdigit: OK");
	else
	{
		printf("isdigit: KO\n");
		printf("\texpected: %d but result: %d", isdigit(c), ft_isdigit(c));
	}
	printf("\n");
}

void	test_isalnum()
{
	int	c = '5';

	if (ft_isalnum(c) == isalnum(c))
		printf("isalnum: OK");
	else
	{
		printf("isalnum: KO\n");
		printf("\texpected: %d but result: %d", isalnum(c), ft_isalnum(c));
	}
	printf("\n");
}

void	test_isascii()
{
	int	c = 128;

	if (ft_isascii(c) == isascii(c))
		printf("isascii: OK");
	else
	{
		printf("isascii: KO\n");
		printf("\texpected: %d but result: %d", isascii(c), ft_isascii(c));
	}
	printf("\n");
}

void	test_isprint()
{
	int	c = 127;

	if (ft_isprint(c) == isprint(c))
		printf("isprint: OK");
	else
	{
		printf("isprint: KO\n");
		printf("\texpected: %d but result: %d", isprint(c), ft_isprint(c));
	}
	printf("\n");
}

void	test_strlen()
{
	const char	*s = "test";

	if (ft_strlen(s) == strlen(s))
		printf("strlen: OK");
	else
	{
		printf("strlen: KO\n");
		printf("\texpected: %lu but result: %lu", strlen(s), ft_strlen(s));
	}
	printf("\n");
}

void	test_memset()
{
	unsigned char	s[] = "aaaaa";
	unsigned char	ft_s[] = "aaaaa";
	size_t	n = 3;
	int		c = 'A';
	size_t	i = 0;

	memset(s, c, sizeof(char) * n);
	ft_memset(ft_s, c, sizeof(char) * n);
	while (i < n)
	{
		if (s[i] != ft_s[i])
		{
			printf("memset: KO\n");
			printf("\texpected: %s but result: %s\n", s, ft_s);
			return;
		}
		i++;
	}
	printf("memset: OK");
	printf("\n");
}

void	test_bzero()
{
	size_t	n = 2;
	char	s[] = "abc";
	char	ft_s[] = "abc";
	size_t	i = 0;

	bzero(s, n);
	ft_bzero(ft_s, sizeof(char) * n);
	while (i < n)
	{
		if (s[i] != ft_s[i])
		{
			printf("bzero: KO\n");
			printf("\texpected: %s but result: %s\n", s, ft_s);
			return;
		}
		i++;
	}
	printf("bzero: OK\n");
}

void	test_memcpy()
{
	size_t	n = 3;
	char	dst[n];
	char	ft_dst[n];
	char	*src = "abc";
	size_t	i = 0;

	memcpy(dst, src, sizeof(char) * n);
	ft_memcpy(ft_dst, src, n);
	while (i < n)
	{
		if(dst[i] != ft_dst[i])
		{
			printf("memcpy: KO\n");
			printf("\texpected: %s but result: %s\n", dst, ft_dst);
			return;
		}
		i++;
	}
	printf("memcpy: OK\n");
}

void	test_memmove()
{
	size_t	n = 3;	// str길이 초과해 입력시 illegal hardware instruction 발생
	char	*dst;
	char	*ft_dst;
	char	ft_src[] = "abc";
	char	src[] = "abc";
	size_t	i = 0;

	dst = &(src[1]);	// 메모리 영역 겹치게 하여 테스트
	ft_dst = &(ft_src[1]);
	memmove(&(src[1]), src, sizeof(char) * n);
	ft_memmove(&(ft_src[1]), ft_src, sizeof(char) * n);
	while (i < n)
	{
		if(dst[i] != ft_dst[i])
		{
			printf("memmove: KO\n");
			printf("\texpected: %s but result: %s\n", dst, ft_dst);
			return;
		}
		i++;
	}
	printf("memmove: OK\n");
}

void	test_strlcpy()
{
	char	dst[] = "0123456789";
	char	ft_dst[] = "0123456789";
	char	src[] = "abcd";
	size_t	n = 3;
	size_t	len = strlcpy(dst, src, n);
	size_t	ft_len = ft_strlcpy(ft_dst, src, n);
	size_t	i = 0;

	if (len == ft_len)
	{
		while (i < n)
		{
			if (dst[i] != ft_dst[i])
			{
				printf("strlcpy: KO\n");
				printf("\texpected dst: %s but result dst: %s\n", dst, ft_dst);
				return;
			}
			i++;
		}
		printf("strlcpy: OK\n");
	}
	else
	{
		printf("strlcpy: KO\n");
		printf("\texpected len: %lu but result len: %lu\n", len, ft_len);
	}
}

void	test_strlcat()
{
	char	dst[20] = "0123";
	char 	ft_dst[20] = "0123";
	char	src[] = "abcdef";
	size_t	n = 8;
	size_t	i = 0;

	ft_strlcat(dst, src, n);
	strlcat(ft_dst, src, n);
	while (i < n)
	{
		if (dst[i] != ft_dst[i])
		{
			printf("strlcat: KO\n");
			printf("\texpected dst: %s but result dst: %s\n", dst, ft_dst);
			return;
		}
		i++;
	}
	printf("strlcat: OK\n");
}

void	test_toupper()
{
	int	c = 'a';
	int res;
	int ft_res;

	res = toupper(c);
	ft_res = ft_toupper(c);
	if (res == ft_res)
		printf("toupper: OK\n");
	else
	{
		printf("toupper: KO\n");
		printf("\texpected: %c but result: %c\n", res, ft_res);
	}
}

void	test_tolower()
{
	int	c = 'A';
	int res;
	int ft_res;

	res = tolower(c);
	ft_res = ft_tolower(c);
	if (res == ft_res)
		printf("tolower: OK\n");
	else
	{
		printf("tolower: KO\n");
		printf("\texpected: %c but result: %c\n", res, ft_res);
	}
}

void	test_strchr()
{
	char	s[] = "aaabbzbcccb";
	int		c = 'd';
	char	*res;
	char	*ft_res;

	res = strchr(s, c);
	ft_res = ft_strchr(s, c);
	if (res == ft_res)
		printf("strchr: OK\n");
	else
	{
		printf("strchr: KO\n");
		printf("\t expected: %p but result: %p\n", res, ft_res);
	}
}

void	test_strrchr()
{
	char	s[] = "aaabbzbcccb";
	int		c = 'a';
	char	*res;
	char	*ft_res;

	res = strrchr(s, c);
	ft_res = ft_strrchr(s, c);
	if (res == ft_res)
		printf("strrchr: OK\n");
	else
	{
		printf("strrchr: KO\n");
		printf("\t expected: %s but result: %s\n", res, ft_res);
	}
}

void	test_strncmp()
{
	//case 1
	char str1[10] = "\200";
	char str2[10] = "\0";
	int	res = strncmp(str1, str2, 5);
	int ft_res = ft_strncmp(str1, str2, 5);

	if (res == ft_res)
		printf("strncmp case 1: OK\n");
	else
	{
		printf("strncmp case 1: OK\n");
		printf("\t expected: %d but result: %d", res, ft_res);
	}

	//case 2
	strcpy(str1, "asdf\0asdf");
	strcpy(str2, "asdf");
	res = strncmp(str1, str2, 5);
	ft_res = ft_strncmp(str1, str2, 5);
	if (res == ft_res)
		printf("strncmp case 2: OK\n");
	else
	{
		printf("strncmp case 2: OK\n");
		printf("\t expected: %d but result: %d", res, ft_res);
	}

	//case 3
	strcpy(str1, "asdf\0asdf");
	strcpy(str2, "asdfff");
	res = strncmp(str1, str2, 5);
	ft_res = ft_strncmp(str1, str2, 5);
	if (res == ft_res)
		printf("strncmp case 3: OK\n");
	else
	{
		printf("strncmp case 3: OK\n");
		printf("\t expected: %d but result: %d", res, ft_res);
	}
}

