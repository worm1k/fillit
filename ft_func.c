/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:52:48 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 13:52:48 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *b, size_t n)
{
	unsigned char	*p;

	p = b;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

int					ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

void				ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

char				*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
