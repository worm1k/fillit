#include "fillit.h"
#include "libft.h"

int			isvalid(char const *path)
{
	char	buf[22];
	int		len;
	int		fd;

	ft_bzero(buf, 22);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("file does not exist", 2);
		exit(1);
	}
	len = read(fd, buf, 21);
	while (len)
	{
		if (len < 20 || !fl_isvalid(buf))
		{
			ft_putendl_fd("Invalid input", 2);
			exit(1);
		}
		ft_bzero(buf, 21);
		len = read(fd, buf, 21);
	}
}

void		fl_read(char const *path, t_lst **head, char letter)
{
	char	buf[22];
	int		len;
	int		fd;

	ft_bzero(buf, 22);
	fd = open(path, O_RDONLY);

	len = read(fd, buf, 21);
	while (len)
	{
		if (len < 20 || !fl_isvalid(buf))
		{
			ft_putendl_fd("Invalid input", 2);
			exit(1);
		}
		fl_add_tetra(head, buf, letter++);
		ft_bzero(buf, 21);
		len = read(fd, buf, 21);
	}
	close(fd);
}

int			main(int argc, char **argv)
{
	t_lst	*head;
	char	*map;
	int		n;
	char	letter;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit source_file", 2);
		return (1);
	}
	n = 2;
	map = fl_getmap(n);
	head = 0;
	letter = 'A';
	fl_read(argv[1], &head, letter);
	while (!fl_solve(map, n, head))
	{
		fl_realloc(&map, ++n);
	}
	printf("%s\n", map);
	return (0);
}