#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "getnextline/get_next_line.h"
#include "cub3d.h"


int main(int ac, char **av)
{
	int fd = 0;
	char *line = NULL;
	int endl = 1;
	t_mapinfo *map;

	map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
	if (ac > 1)
	{
		init_mapinfo(map);
		map->file = av[1];
		fd = open(map->file, O_RDONLY);
		while (endl > 0)
		{
			endl = get_next_line(fd, &line);
			empty_line(line) != 1 ? getinfo(fd, line, map) : 0;		
			free(line);
			line = NULL;
		}	
		close(fd);	
	}
	return (0);
}

