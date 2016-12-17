
#include "fillit.h"
#include "libft.h"

t_lst		*fl_lstnew(t_tetra *tetra)
{
	t_lst	*res;

	res = (t_lst *)malloc(sizeof(t_lst));
	res->tetra = tetra;
	res->next = NULL;

	return (res);
}

t_tetra		*fl_tetranew(char *buf, int len, int hei)
{
	t_tetra	*res;

	res = (t_tetra *)malloc(sizeof(t_tetra));
	res->str = ft_strdup(buf);
	res->len = len;
	res->hei = hei;
	return (res);
}

void		fl_lstpush_back(t_lst **lst, t_tetra *tetra)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!*lst)
	{
		printf("CREATED\n");
		*lst = fl_lstnew(tetra);
		return ;
	}
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
	}
	printf("PUSHED\n");
	(*lst)->next = fl_lstnew(tetra);
	*lst = tmp;
}

void		fl_print_lst(t_lst *lst)
{
	while (lst)
	{
		printf("%s\n", lst->tetra->str);
		lst = lst->next;
	}
}
