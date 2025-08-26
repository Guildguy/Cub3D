#include "cub3d.h"

char	**create_hard_map(void)
{
	char	**map;

	map = ft_calloc(8, sizeof(char *));
	map[0] = ft_strdup("111111111");
	map[1] = ft_strdup("1S0000001");
	map[2] = ft_strdup("101000101");
	map[3] = ft_strdup("111000111");
	map[4] = ft_strdup("100000001");
	map[5] = ft_strdup("101000101");
	map[6] = ft_strdup("111111111");
	map[7] = NULL;
	return (map);
}
