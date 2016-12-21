/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		fl_is4x4(char *buf)
{
	if (ft_strlen(buf) < 20)
		return (0);
	if (buf[4] != '\n'
		|| buf[9] != '\n'
		|| buf[14] != '\n'
		|| buf[19] != '\n')
		return (0);
	if (buf[20] == '\n' || buf[20] == '\0')
		return (1);
	return (0);
}

static int		fl_has_right_chars(char *buf)
{
	int			i;
	int			hashes;
	int			dots;
	int			returns;

	hashes = 0;
	dots = 0;
	returns = 0;
	i = 0;
	while (i < 20 && buf[i])
	{
		if (buf[i] == '#')
			hashes += 1;
		if (buf[i] == '.')
			dots += 1;
		if (buf[i] == '\n')
			returns += 1;
		i++;
	}
	if (hashes == 4 && dots == 12 && returns == 4)
		return (1);
	return (0);
}

static int		fl_tetramine(char *buf)
{
	int			i;
	int			joins;

	i = 0;
	joins = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (0 <= i - 5 && buf[i - 5] == '#')
				joins += 1;
			if (i + 5 < 20 && buf[i + 5] == '#')
				joins += 1;
			if (i != 0 && buf[i - 1] == '#')
				joins += 1;
			if (buf[i + 1] == '#')
				joins += 1;
		}
		i++;
	}
	if (joins == 6 || joins == 8)
		return (1);
	return (0);
}

int				fl_isvalid(char *buf)
{
	if (fl_is4x4(buf))
	{
		if(fl_has_right_chars(buf))
		{
			if(fl_tetramine(buf))
			{
				return (1);
			}
		}
	}
	return (0);
}