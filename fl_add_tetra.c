
#include "fillit.h"
#include "libft.h"

void	fl_lstpush_back(t_list *lst, char *buf)
{
	if (!lst)
		lst = (t_list *)malloc(sizeof(t_list));
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = (t_list *)malloc(sizeof(t_list));
	lst->next->tetra->str = ft_strdup(buf);
	lst->next->next = NULL;
}

t_tetra		*fl_trimtetra(char *buf)
{
	int		
}