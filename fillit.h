#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int					fl_isvalid(char *buf);
size_t				ft_strlen(const char *s);
char				*fl_generate_nmap(size_t x, size_t y);
char				*fl_getmap(size_t n);
typedef struct		s_tetra
{
	char			*str;
	int				len;
	int				hei;
}					t_tetra;
typedef struct		s_list
{
	t_tetra			*tetra;
	struct s_list	*next;
}					t_list;
#endif