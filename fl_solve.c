
#include "fillit.h"
#include "libft.h"

static void	fl_delete(char *map, int n, int index, t_tetra *tetra)
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
static void	fl_insert(char *map, int n, int index, t_tetra *tetra)
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

static int	fl_fits(char *map, int n, int index, t_tetra *tetra)
{
	int		i;
	char	*fig;
	int		mem;

	i = 0;
	fig = tetra->str;
	mem = index;
	while(fig[i] != '\0')
	{
		if (ft_isupper(fig[i]) && (map[index] != '.' || map[index] == fig[i]))
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

static int	fl_free_slot(char *map, int n, int index, t_tetra *tetra)
{
	int		i;

	i = index;
	while (map[i] != '\0')
	{
		if (i % (n + 1) + tetra->len < n + 1
			&& i / (n + 1) + tetra->hei < n + 1)
		{
			if (fl_fits(map, n, i, tetra))
				return (i);
		}
		i++;
	}
	return (-1);
}

int			fl_solve(char *map, int n, t_lst *lst)
{
	int		i;
	int		temp;

	i = fl_free_slot(map, n, 0, lst->tetra);
	while (i != -1)
	{
		//printf("INSERTED%d\n", i);
		fl_insert(map, n, i, lst->tetra);
		//printf("MAP:\n%s", map);
		if (!lst->next)
		{
			return (1);
		}
		if (fl_solve(map, n, lst->next))
		{
			return (1);
		}
		temp = i;
		fl_delete(map, n, temp, lst->tetra);
		i = fl_free_slot(map, n, i + 1, lst->tetra);
		//printf("DELETED:%d\n", temp);
		//printf("NEXT:%d\n", i);
	}
	return (0);
}