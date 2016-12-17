
#include "fillit.h"
#include "libft.h"

int		fl_get_height(char *buf)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			res++;
		i++;
	}
	return (res);
}
