
#include "fillit.h"
#include "libft.h"

void	fl_delete(char *map, int n, int index, t_tetra *tetra)
{
	int		i;
	char	*fig;
	int		mem;

	i = 0;
	fig = tetra->str;
	mem = index;
	while(fig[i] != '\0')
	{
		if (ft_isupper(fig[i]))
			map[index] = '.';
		if (fig[i] == '\n')
		{
			index = mem + n + 1;
			mem = index;
		}
		else
		{
			index++;
		}
		i++;
	}
}
void	fl_insert(char *map, int n, int index, t_tetra *tetra)
{
	int		i;
	char	*fig;
	int		mem;

	i = 0;
	fig = tetra->str;
	mem = index;
	while(fig[i] != '\0')
	{
		if (ft_isupper(fig[i]))
			map[index] = fig[i];
		if (fig[i] == '\n')
		{
			index = mem + n + 1;
			mem = index;
		}
		else
		{
			index++;
		}
		i++;
	}
}

int		fl_fits(char *map, int n, int index, t_tetra *tetra)
{
	int		i;
	char	*fig;
	int		mem;

	i = 0;
	fig = tetra->str;
	mem = index;
	while(fig[i] != '\0')
	{
		if (ft_isupper(fig[i]) && map[index] != '.')
			return (0);
		if (fig[i] == '\n')
		{
			index = mem + n + 1;
			mem = index;
		}
		else
		{
			index++;
		}
		i++;
	}
	return (1);
}

int			fl_free_slot(char *map, int n, t_tetra *tetra)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		if (fl_fits(map, n, i, tetra))
			return (i);
		i++;
	}
	return (-1);
}