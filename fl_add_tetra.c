/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_add_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fl_isfree(char c)
{
	if (c == '.' || c == '*')
		return (1);
	return (0);
}

static void	fl_mark_extra_rows(char *buf)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (fl_isfree(buf[i]) && fl_isfree(buf[i + 1])
		&& fl_isfree(buf[i + 2]) && fl_isfree(buf[i + 3]))
			ft_memset(buf + i, '*', 5);
		i += 5;
	}
	buf[20] = '\0';
}

static int	fl_get_height(char *buf)
{
	int		i;
	int		res;

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

static void	fl_mark_extra_cols(char *buf)
{
	int		i;

	i = 0;
	while (i < 4)
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
	//printf("ADDING:\n%s======\n", res);
	len = ft_strchr(res, '\n') - res;
	fl_lst_pushback(lst, fl_tetranew(res, len, fl_get_height(res)));
}
