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
size_t				ft_strlen(const char *s);
char				*fl_generate_nmap(size_t x, size_t y);
char				*fl_getmap(size_t n);
void				fl_realloc(char **map, int n);
void				fl_mark_extra_rows(char *buf);
void				fl_mark_extra_cols(char *buf);
int					fl_get_height(char *buf);
void				fl_add_tetra(t_lst **lst, char *buf, char letter);
void				fl_lstpush_back(t_lst **lst, t_tetra *tetra);
t_tetra				*fl_tetranew(char *buf, int len, int hei);
void				fl_print_lst(t_lst *lst);
int					fl_free_slot(char *map, int n, int i, t_tetra *tetra);
int					fl_fits(char *map, int n, int index, t_tetra *tetra);
int					fl_solve(char *map, int n, t_lst *lst);
void				fl_delete(char *map, int n, int index, t_tetra *tetra);
void				fl_insert(char *map, int n, int index, t_tetra *tetra);
#endif