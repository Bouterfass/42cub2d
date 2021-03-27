#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "getnextline/get_next_line.h"
#include "cub3d.h"

/*
	- récup la ligne
	- la trim 
	- réduire tout les espaces à 1
	- stocker
*/




int main(int ac, char **av)
{
	int fd = 0;
	char *line = NULL;
	int i = 0;
	int endl = 1;
	t_mapinfo *map;

	map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
	if (ac > 1)
	{
		init_mapinfo(map);
		while (i < ac)
		{	
			fd = open(av[1], O_RDONLY);
			while (endl > 0)
			{
				endl = get_next_line(fd, &line);
				if (empty_line(line) != 1)
					getinfo(line, map);
				
				free(line);
				line = NULL;
			}
			i++;
			close(fd);
		}
	}

	return (0);
}

