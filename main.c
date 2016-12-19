#include "fillit.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[22];
	int		len;
	t_lst	*head;
	char	letter;
	char	*map;
	int		n;

	n = 2;
	map = fl_getmap(n);
	head = 0;
	letter = 'A';
	ft_bzero(buf, 22);
	fd = open("tetra.tx", O_RDONLY);
	len = read(fd, buf, 21);
	
	while (len)
	{
		if (len < 20 || !fl_isvalid(buf))
		{
			printf("Error\n");
			return (1);
		}
		fl_add_tetra(&head, buf, letter++);
		ft_bzero(buf, 21);
		len = read(fd, buf, 21);
	}

	while (!fl_solve(map, n, head))
	{
		fl_realloc(&map, ++n);
	}
	close(fd);

	return (0);
}