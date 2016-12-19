
#include "fillit.h"
#include "libft.h"

int			fl_isfree(char c)
{
	if (c == '.' || c == '*')
		return (1);
	return (0);
}

void		fl_mark_extra_rows(char *buf)
{
	int		i;

	i = 0;
	while(i < 16)
	{
		if (fl_isfree(buf[i]) && fl_isfree(buf[i + 1])
		&& fl_isfree(buf[i + 2]) && fl_isfree(buf[i + 3]))
				ft_memset(buf + i, '*', 5);
		i += 5;
	}
	buf[20] = '\0';
}

void		fl_mark_extra_cols(char *buf)
{
	int		i;

	i = 0;
	while(i < 4)
	{
		if (fl_isfree(buf[i]) && fl_isfree(buf[i + 5])
		&& fl_isfree(buf[i + 10]) && fl_isfree(buf[i + 15]))
			{
				buf[i] = '*';
				buf[i + 5] = '*';
				buf[i + 10] = '*';
				buf[i + 15] = '*';
			}
		i++;
	}
}

void		fl_add_tetra(t_lst **lst, char *buf, char letter)
{
	char	res[10];
	int		i;
	int		j;
	int		len;

	fl_mark_extra_rows(buf);
	fl_mark_extra_cols(buf);
	i = 0;
	j = 0;
	ft_bzero(res, 10);
	while (buf[i])
	{
		if (buf[i] == '#')
			res[j++] = letter;
		if (buf[i] == '.' || buf[i] == '\n')
		{
			res[j++] = buf[i];
		}
		i++;
	}
	printf("ADDING:\n%s======\n", res);
	len = ft_strchr(res, '\n') - res;
	fl_lstpush_back(lst, fl_tetranew(res, len, fl_get_height(res)));
}
