#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


char*		ft_base(unsigned int n, int b)
{
	char *ret = malloc(17);
	char *r = malloc(17);
	memset((void*)ret, 0, 17);
	memset((void*)r, 0, 17);
	int j = 0;
	int i = 0;
	while (n)
	{
		if (n % b < 10)
			ret[i++] = (n % b) + 48;
		else
			ret[i++] = (n % b) + 55;
		n /= b;
	}
	while (--i)
		r[j++] = ret[i];
	return (r);
}

char	*ft_get(char *arv)
{
	char *av = malloc(17);
	memset((void*)av, 0, 17);
	int i = 0;
	int j = 0;
	while ((av[j++] = arv[i++]))
		;
	if (strlen(arv) % 2)
		av[--j] = '0';
	return (av);
}

void	ft_format(char *arv)
{
	char ret[17];
	char *av = ft_get(arv);
	memset((void*)ret, 0, 17);
	int j = 0;
	int i = strlen(av) - 1;
	while (i >= 0 )
	{
		ret[j++] +=  '\\';
		ret[j++] += 'x';
		ret[j++] = av[i - 1];
		ret[j++] = av[i];
		i -= 2;
	}
	printf("%s\n", ret);
}

int		main(int ac, char **av)
{
	char *ptr = getenv(av[1]);
	if (!ptr)
		ft_format(av[1]);
	else
		ft_format(ft_base((unsigned int)ptr, 16));
	return 0;
}
