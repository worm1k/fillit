#include "fillit.h"
#include "libft.h"

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
	memset(res, '.', len);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		if ((i + 1) % (x + 1) == 0)
			res[i] = '\n';
		i++;
	}
	return (res);
}
