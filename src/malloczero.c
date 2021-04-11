#include "../includes/cub3d.h"

void	ft_bzero(void *block, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = block;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*malloczero(size_t size)
{
	void	*dest;

	if ((dest = malloc(size)))
		ft_bzero(dest, size);
	return (dest);
} 
