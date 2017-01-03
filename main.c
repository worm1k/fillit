/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fl_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
	{
		i++;
	}
	return (i - 1);
}

int			isvalid(char const *path, int fd)
{
	char	buf[22];
	int		len;
	char	last;

	ft_bzero(buf, 22);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		ft_putendl_fd("error", 1);
		exit(1);
	}
	len = read(fd, buf, 21);
	while (len)
	{
		if (len < 20 || !fl_isvalid(buf))
		{
			ft_putendl_fd("error", 1);
			exit(1);
		}
		last = buf[20];
		ft_bzero(buf, 21);
		len = read(fd, buf, 21);
	}
	if (!last)
		return (1);
	return (0);
}

int			fl_read(char const *path, t_lst **head)
{
	char	buf[22];
	int		len;
	int		fd;
	char	letter;
	int		count;

	fd = open(path, O_RDONLY);
	ft_bzero(buf, 22);
	len = read(fd, buf, 21);
	if (len == 0)
	{
		ft_putendl_fd("error", 1);
		exit(1);
	}
	letter = 'A';
	count = 0;
	while (len)
	{
		count++;
		fl_add_tetra(head, buf, letter++);
		ft_bzero(buf, 21);
		len = read(fd, buf, 21);
	}
	close(fd);
	return (count);
}

int			main(int argc, char **argv)
{
	t_lst	*head;
	char	*map;
	int		n;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit source_file", 1);
		return (1);
	}
	head = 0;
	if (isvalid(argv[1], fd = -1))
		fl_read(argv[1], &head);
	else
	{
		ft_putendl_fd("error", 1);
		return (1);
	}
	n = 2;
	map = fl_getmap(n);
	while (!fl_solve(map, n, head))
		fl_realloc(&map, ++n);
	ft_putstr(map);
	fl_clean(map, &head);
	return (0);
}
