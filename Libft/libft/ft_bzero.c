#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temporary;

	temporary = (unsigned char *) s;
	while (n > 0)
	{
		*(temporary++) = 0;
		n--;
	}
}
