#include "fillit.h"

int			main()
{
	int		fd;
	char	buf[22];
	int		len;

	for (int i = 0; i < 22; i++) buf[i++] = 0;
	fd = open("tetra.tx", O_RDONLY);
	len = read(fd, buf, 21);
	char *map = fl_generate_map(5);
	printf("%s", map);
	/*
	while (len)
	{
		if (len < 20 || !fl_isvalid(buf))
		{
			printf("Error\n");
			return (1);
		}
		printf("len: %d\n%s", len, buf);
		len = read(fd, buf, 21);
	}
	*/
	close(fd);
	return 0;
}