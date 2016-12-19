#include "fillit.h"
#include "libft.h"

void		fl_realloc(char **map, int n)
{
	free(*map);
	*map = fl_generate_nmap(n, n);
	printf("GENERATED%d\n", n);
}

char		*fl_getmap(size_t n)
{
	return (fl_generate_nmap(n, n));
}

char		*fl_generate_nmap(size_t x, size_t y)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = (x + 1) * y;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_memset(res, '.', len);
	res[len] = '\0';
	i = x;
	while (i < len)
	{
		res[i] = '\n';
		i += x + 1;
	}
	return (res);
}
