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
	char *line = NULL;
	int endl = 1;
	t_mapinfo *map;

	map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
	if (ac > 1)
	{
		init_mapinfo(map);
		map->file = av[1];
		map->fd = open(map->file, O_RDONLY);
		while (endl > 0)
		{
			endl = get_next_line(map->fd, &line);
			empty_line(line) != 1 ? getinfo(line, map) : 0;		
			free(line);
			line = NULL;
		}
		print_map(map->map);
		close(map->fd);	
	}
	return (0);
}



/*
int main(int ac, char const *av[])
{
	int fd = 0;
	char *line = NULL;
	int endl = 1;
	int i = 1;


	if (ac > 1)
	{
		while (i < ac)
		{
			fd = open(av[1], O_RDONLY);
			endl = 1;
			while (endl > 0)
			{
				endl = get_next_line(fd, &line);
				if (endl >= 0)
				{
					printf("endl: %i | %s\n",endl, line);
					free(line);
					line = NULL;
				}
				else
					printf("endl: %i\n", endl);
			}
			close(fd);
			i++;
		}
	}
	return (0);
}*/