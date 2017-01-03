/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fl_realloc(char **map, int n)
{
	free(*map);
	*map = fl_generate_nmap(n, n);
}

char		*fl_getmap(int n)
{
	return (fl_generate_nmap(n, n));
}

char		*fl_generate_nmap(int x, int y)
{
	char	*res;
	int		len;
	int		i;

	len = (x + 1) * y;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_memset(res, '.', len);
	res[len] = '\0';
	i = x;
	while (i < len)
	{
		res[i] = '\n';
		i += x + 1;
	}
	return (res);
}
