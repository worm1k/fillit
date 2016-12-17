
#include "fillit.h"
#include "libft.h"

int		fl_solve(char *map, int n, t_lst *lst)
{
	int	i;

	i = fl_free_slot(map, n, lst->tetra);
	while (i != -1)
	{
		fl_insert(map, n, i, lst->tetra);
		if (!lst->next)
		{
			return (1);
		}
		if (fl_solve(map, n, lst->next))
			return (1);
		fl_delete(map, n, i, lst->tetra);
		i = fl_free_slot(map, n, lst->tetra);
	}
	return (0);
}