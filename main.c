#include "fillit.h"

int			main()
{
	int		fd;
	char	buf[100];
	int		len;

	for (int i = 0; i < 100; i++) buf[i++] = 0;
	fd = open("tetra.tx", O_RDONLY);
	len = read(fd, buf, 21);
	while (len > 19)
	{
		if (!fl_isvalid(buf))
		{
			printf("Error\n");
			return (1);
		}
		printf("len: %d\n%s", len, buf);
		len = read(fd, buf, 21);
	}
	close(fd);
	return 0;
}