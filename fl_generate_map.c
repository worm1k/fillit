#include "fillit.h"

char		*fl_generate_map(size_t n)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = (n + 1) * n;

	res = (char *)malloc(sizeof(char) * (len + 1));
	memset(res, '.', len);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		if ((i + 1) % (n + 1) == 0)
			res[i] = '\n';
		i++;
	}
	return (res);
}
