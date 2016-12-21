/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_free_slot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			fl_free_slot(char *map, int n, int index, t_tetra *tetra)
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