
#include "fillit.h"
#include "libft.h"

int		fl_solve(char *map, int n, t_lst *lst)
{
	int	i;
	int	temp;

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