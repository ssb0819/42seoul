#include "../libft.h"
#include "test_libft.h"

int	main(void)
{
	// part1
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
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	// part2
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
}

void	test_isalpha()
{
	int c = 850;

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
	int		c = 256;
	size_t	i = 0;

	memset(s, c, sizeof(char) * n);
	ft_memset(ft_s, c, sizeof(char) * n);
	while (i < n)
	{
		if (1)
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
	char	s[] = "abc";	// NULL이면 segmentation fault
	char	ft_s[] = "abc";	// NULL이면 segmentation fault
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
	// case 1
	int		flag = 1;
	size_t	n = 3;
	char	dst[n];
	char	ft_dst[n];
	char	*src = "abc";

	memcpy(dst, src, sizeof(char) * n);
	ft_memcpy(ft_dst, src, n);

	if (ft_strncmp(dst, ft_dst, n) != 0)
	{
		printf("memcpy case 1: KO\n");
		printf("\texpected: %s but result: %s\n", dst, ft_dst);
		flag = 0;
	}
	memcpy(NULL, NULL, 3);
	ft_memcpy(NULL, NULL, 3);
	if (ft_strncmp(dst, ft_dst, n) != 0)
	{
		printf("memcpy case 2: KO\n");
		printf("\texpected: %s but result: %s\n", dst, ft_dst);
		flag = 0;
	}
	if (flag)
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
	size_t	n = 1;
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
		printf("\texpected dst: %s but result dst: %s\n", dst, ft_dst);
	}
}

void	test_strlcat()
{
	char	dst[20] = "0123";
	char 	ft_dst[20] = "0123";
	char	src[] = "abcdef";
	size_t	n = 0;

	int ft_res = ft_strlcat(NULL, src, n);
	int res = strlcat(NULL, src, n);
	if (ft_strncmp(dst, ft_dst, n) != 0 || res != ft_res)
	{
		printf("strlcat: KO\n");
		printf("\texpected dst: %s but result dst: %s\n", dst, ft_dst);
		printf("\treturn - res: %d // ft_res:%d\n", res, ft_res);
		return;
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
	char	*s;
	int		c;
	char	*res;
	char	*ft_res;
	int		flag;

	flag = 1;
	// case 1
	s  = "aaabbzbcccb";
	c = 'd';
	res = strchr(s, c);
	ft_res = ft_strchr(s, c);
	if (res != ft_res)
	{
		printf("strchr case 1: KO\n");
		printf("\t expected: %p but result: %p\n", res, ft_res);
		flag = 0;
	}
	// case 2
	s = "";
	c = '\0';
	res = strchr(s, c);
	ft_res = ft_strchr(s, c);
	if (res != ft_res)
	{
		printf("strchr case 2: KO\n");
		printf("\t expected: %s but result: %s\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("strchr: OK\n");
}

void	test_strrchr()
{
	char	*s;
	int		c;
	char	*res;
	char	*ft_res;
	int		flag;

	// case 1
	s = "aaabbzbcccb";
	c = 'b';
	res = strrchr(s, c);
	ft_res = ft_strrchr(s, c);
	if (res != ft_res)
	{
		printf("strrchr case 1: KO\n");
		printf("\t expected: %s but result: %s\n", res, ft_res);
		flag = 0;
	}
	// case 2
	s = "";
	c = '\0';
	res = strchr(s, c);
	ft_res = ft_strchr(s, c);
	if (res != ft_res)
	{
		printf("strchrr case 2: KO\n");
		printf("\t expected: %s but result: %s\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("strrchr: OK\n");
}

void	test_strncmp()
{
	size_t	n = -1;
	int		flag = 1;

	//case 1
	char str1[10] = "\200";
	char str2[10] = "\188";
	int	res = strncmp(str1, str2, n);
	int ft_res = ft_strncmp(str1, str2, n);

	if (res != ft_res)
	{
		printf("strncmp case 1: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	//case 2
	strcpy(str1, "asdf\0asdf");
	strcpy(str2, "asdf");
	res = strncmp(str1, str2, n);
	ft_res = ft_strncmp(str1, str2, n);
	if (res != ft_res)
	{
		printf("strncmp case 2: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	//case 3
	strcpy(str1, "asdf\0asdf");
	strcpy(str2, "asdfff");
	res = strncmp(str1, str2, n);
	ft_res = ft_strncmp(str1, str2, n);
	if (res != ft_res)
	{
		printf("strncmp case 3: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("strncmp: OK\n");
}
 
void	test_memchr()
{
	int		flag = 1;
	// case 1
	char	s[] = "aadabbzbcccb";
	int		c = 'e';
	char	*res;
	char	*ft_res;
	size_t	n = 15;

	res = memchr(s, c, n);
	ft_res = ft_memchr(s, c, n);
	if (res != ft_res)
	{
		printf("memchr: KO\n");
		printf("\t expected: %p but result: %p\n", res, ft_res);
		flag = 0;
	}
	// case 2
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	res = (char *)memchr(tab, -1, 7);
	ft_res = (char *)ft_memchr(tab, -1, 7);
	if (res != ft_res)
	{
		printf("memchr: KO\n");
		printf("\t expected: %p but result: %p\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("memchr: OK\n");
}

void	test_memcmp()
{

	size_t n = 5;
	int	flag = 1;

	//case 1
	char str1[10] = "\200";
	char str2[10] = "\200";
	int	res = memcmp(str1, str2, n);
	int ft_res = ft_memcmp(str1, str2, n);
	if (res != ft_res)
	{
		printf("memcmp case 1: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	//case 2
	strcpy(str1, "asdfg\0asdf");
	strcpy(str2, "asdfg");
	res = memcmp(str1, str2, n);
	ft_res = ft_memcmp(str1, str2, n);
	if (res != ft_res)
	{
		printf("memcmp case 2: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	//case 3
	strcpy(str1, "a");
	strcpy(str2, "a");
	res = memcmp(str1, str2, n);
	ft_res = ft_memcmp(str1, str2, n);
	if (res != ft_res)
	{
		printf("memcmp case 3: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("memcmp: OK\n");
}

void	test_strnstr()
{
	char str[] = "0123456789";
	char to_find[] = "234";
	size_t n = 0;
	char	*res;
	char	*ft_res;

	res = strnstr(str, to_find, n);
	ft_res = ft_strnstr(str, to_find, n);
	if (res == ft_res)
		printf("strnstr: OK\n");
	else
	{
		printf("strnstr: KO\n");
		printf("\t expected: %s but result: %s\n", res, ft_res);
	}
}

void	test_atoi()
{
	char max[] = "9223372036854775807"; // LONG_MAX
	char min[] = "-9223372036854775808"; // LONG_MIN
	char s[] = "+0000000000000000000000000000000000000000000000000000123";
	int flag = 1;
	int res = atoi(s);
	int ft_res = ft_atoi(s);

	if (res != ft_res)
	{
		printf("atoi case 1: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	res = atoi(max);
	ft_res = ft_atoi(max);
	if (res != ft_res)
	{
		printf("atoi case 2 - max value test: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	res = atoi(min);
	ft_res = ft_atoi(min);
	if (res != ft_res)
	{
		printf("atoi case 3 - min value test: KO\n");
		printf("\t expected: %d but result: %d\n", res, ft_res);
		flag = 0;
	}
	if (flag)
		printf("atoi: OK\n");
}

void	test_calloc()
{
	size_t	size = sizeof(char);
	size_t	count = 2;
	char	*p;
	char	*ft_p;
	size_t	i;

	i = 0;
	p = (char *)calloc(count, size);
	ft_p = (char *)ft_calloc(count, size);

	while (i < count)
	{
		if (p[i] != ft_p[i])
		{
			printf("calloc: KO\n");
			printf("\tindex: %d// expected: %d but result: %d\n",(int)i, p[i], ft_p[i]);
			free(p);
			free(ft_p);
			return ;
		}
		i++;
	}
	printf("calloc: OK\n");
	free(p);
	free(ft_p);
}

void	test_strdup()
{
	char	*s = "";
	size_t	len = strlen(s);
	char	*res;
	char	*ft_res;

	res = strdup(s);
	ft_res = ft_strdup(s);
	if (ft_strncmp(res, ft_res, len))
	{
		printf("strdup: KO\n");
		printf("\texpected: %s but result: %s\n", res, ft_res);
	}
	else
		printf("strdup: OK\n");
	free(res);
	free(ft_res);
}

void	test_substr()
{
	const char		*s;
	char			*res;
	char			*ans;
	unsigned int	start;
	size_t			len;
	size_t			i;
	int				flag;
	
	flag = 1;
	// case 1
	s = "0123456789";
	start = 1;
	len = 3;
	ans = "123";
	i = 0;
	res = ft_substr(s, start, len);
	if (ft_strncmp(res, ans, len) != 0)
	{
		printf("substr case 1: KO\n");
		printf("\texpected res: %s but result: %s\n", ans, res);
		flag = 0;

	}
	free(res);
	// case 2 [start > string length]
	start = 20;
	len = 2;
	res = ft_substr(s, start, len);
	if (res != 0 && *res != 0)
	{
		printf("substr case 2 [start > string length]: KO\n");
		printf("\texpected null string but result: %c\n", *res);
		flag = 0;
	}
	free(res);
	// case 3 [len = 0 OR s = ""] -> malloc(0): UB
	s = "";
	start = 0;
	len = 0;
	res = ft_substr(s, start, len);
	if (res != 0 && *res != 0)
	{
		printf("substr case 3 [len = 0]: KO\n");
		printf("\texpected null string but result: %c\n", *res);
		flag = 0;
	}
	free(res);
	if (flag)
		printf("substr: OK\n");
}

void	test_strjoin()
{
	const char	*s1;
	const char	*s2;
	char		*ans;
	size_t		n;
	char		*res;
	int			flag;

	flag = 1;
	// case 1
	s1 = "12345";
	s2 = "67890";
	ans = "1234567890";
	n = 10;
	res = ft_strjoin(s1, s2);
	if (ft_strncmp(res, ans, n) != 0)
	{
		printf("strjoin case 1: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 2 [s1 = \"\"]
	s1 = "";
	ans = "67890";
	n = 5;
	res = ft_strjoin(s1, s2);
	if (ft_strncmp(res, ans, n) != 0)
	{
		printf("strjoin case 2 [s1 = \"\"]: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 3 [s = NULL]
	s1 = NULL;
	s2 = NULL;
	res = ft_strjoin(s1, s2);
	if (res != NULL)
	{
		printf("strjoin case 3 [s = NULL]: KO\n");
		printf("\texpected NULL but result IS NOT NULL\n");
		flag = 0;
	}
	if (flag)
		printf("strjoin: OK\n");
}

void	test_strtrim()
{
	char	*s;
	char	*set;
	char	*ans;
	char	*res;
	size_t	ans_len;
	int		flag;

	// case 1
	s = "aaabbccddcacab";
	set = "ab";
	ans = "ccddcac";
	ans_len = 7;
	res = ft_strtrim(s, set);
	if (ft_strncmp(res, ans, ans_len) != 0)
	{
		printf("strtrim case 1: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 2 [set = ""]
	s = "0123456789";
	set = "";
	ans = "0123456789";
	ans_len = 10;
	res = ft_strtrim(s, set);
	if (ft_strncmp(res, ans, ans_len) != 0)
	{
		printf("strtrim case 2[set = \"\"]: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 3 [s = NULL]
	s = NULL;
	set = "abc";
	res = ft_strtrim(s, set);
	if (res != NULL)
	{
		printf("strtrim case 3 [s = NULL]: KO\n");
		printf("\texpected NULL but result IS NOT NULL\n");
		flag = 0;
	}
	free(res);
	// case 4 [trim all]
	s = "aabbbaab";
	set = "ab";
	ans = "";
	res = ft_strtrim(s, set);
	if (*res != 0)
	{
		printf("strtrim case 4 [trim all]: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	if (flag)
		printf("strtrim: OK\n");
}

void	test_split()
{
	char	*s;
	char	c;
	int		cnt;
	char	**res;

	// case 1
	s = "aa,,c";
	c = ',';
	cnt = 2;
	res = ft_split(s, c);

	printf("split case 1: Check for yourself\n\ts: %s\n\tc: %c\n", s, c);
	for (int i = 0; i < cnt; i++)
	{
		printf("\tresult[%d]: %s\n", i, res[i]);
	}
	// case 2
	s = "aaaaaa";
	c = 'a';
	cnt = 0;
	res = ft_split(s, c);
	printf("split case 2: Check for yourself\n\ts: %s\n\tc: %c\n", s, c);
	for (int i = 0; i < cnt; i++)
	{
		printf("\tresult[%d]: %s\n", i, res[i]);
	}
	printf("\tresult: %s\n", res[0]);
	// case 3
	s = NULL;
	c = '\0';
	cnt = 0;
	res = ft_split(s, c);
	printf("split case 3: Check for yourself\n\ts: %s\n\tc: %c\n", s, c);
	for (int i = 0; i < cnt; i++)
	{
		printf("\tresult[%d]: %s\n", i, res[i]);
	}
	//printf("\tresult: %s\n", res[0]);
}

void	test_itoa()
{
	int		n;
	char	*res;
	char	*ans;
	size_t	len;
	int		flag;

	flag = 1;
	// case 1
	n = 0;
	ans = "0";
	len = ft_strlen(ans);
	res = ft_itoa(n);
	if (ft_strncmp(ans, res, len) != 0)
	{
		printf("itoa case 1: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 2
	n = -12345;
	ans = "-12345";
	len = ft_strlen(ans);
	res = ft_itoa(n);
	if (ft_strncmp(ans, res, len) != 0)
	{
		printf("itoa case 2: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	free(res);
	// case 2 [INT_MIN]
	n = -2147483648;
	ans = "-2147483648";
	len = ft_strlen(ans);
	res = ft_itoa(n);
	if (ft_strncmp(ans, res, len) != 0)
	{
		printf("itoa case 3 [INT_MIN]: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	if (flag)
		printf("itoa: OK\n");
}

char	ft_strmapi_test(unsigned int i, char c)
{
	if (i == 0 && c >= 'a' && c <= 'z')
		c -= 32;
	else if(i != 0 && c >= 'A' && c<= 'Z')
		c += 32;
	return (c);
}

void	test_strmapi()
{
	char	(*f)(unsigned int, char);
	char	*s;
	size_t	len;
	char	*res;
	char	*ans;
	int		flag;

	f = ft_strmapi_test;
	flag = 1;
	// case 1
	s = "abcde";
	ans = "Abcde";
	len = ft_strlen(ans);
	res = ft_strmapi(s, f);
	if (ft_strncmp(res, ans, len) != 0)
	{
		printf("strmapi: KO\n");
		printf("\texpected: %s but result: %s\n", ans, res);
		flag = 0;
	}
	if (flag)
		printf("strmapi: OK\n");
}

void	ft_striteri_test(unsigned int i, char *c)
{
	if (i == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
	else if(i != 0 && *c >= 'A' && *c<= 'Z')
		*c += 32;
}

void	test_striteri()
{
	void	(*f)(unsigned int, char*);
	char	s[] = "abcde";
	size_t	len;
	char	*ans;
	int		flag;

	f = ft_striteri_test;
	flag = 1;
	ans = "Abcde";
	len = ft_strlen(ans);
	ft_striteri(s, f);
	if (ft_strncmp(s, ans, len) != 0)
	{
		printf("striteri: KO\n");
		printf("\texpected: %s but result: %s\n", ans, s);
		flag = 0;
	}
	if (flag)
		printf("striteri: OK\n");
}

void	test_putchar_fd()
{
	write(1, "putchar_fd: ", 12);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	write(1, "\n", 1);
}

void	test_putstr_fd()
{
	char *s = "OK";
	write(1, "putstr_fd: ", 11);
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
}

void	test_putendl_fd()
{
	char *s = "OK";
	write(1, "putendl_fd: ", 12);
	ft_putendl_fd(s, 1);
}

void	test_putnbr_fd()
{
	int n = -2147483648;
	write(1, "putnbr_fd: check for yourself\n\t", 30);
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
}
