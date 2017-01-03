/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:34 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 10:55:36 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_tetra
{
	char			*str;
	int				len;
	int				hei;
}					t_tetra;

typedef struct		s_lst
{
	t_tetra			*tetra;
	struct s_lst	*next;
}					t_lst;

int					fl_isvalid(char *buf);
char				*fl_generate_nmap(int x, int y);
char				*fl_getmap(int n);
void				fl_realloc(char **map, int n);
void				fl_add_tetra(t_lst **lst, char *buf, char letter);
void				fl_lst_pushback(t_lst **lst, t_tetra *tetra);
t_tetra				*fl_tetranew(char *buf, int len, int hei);
void				fl_print_lst(t_lst *lst);
int					fl_solve(char *map, int n, t_lst *lst);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *b, size_t n);
int					ft_isupper(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *b, size_t n);
int					ft_isupper(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				fl_clean(char *map, t_lst **lst);
#endif
