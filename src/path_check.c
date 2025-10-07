#include "mlx.h"
#include "solong.h"

void	find_player(char **map, int *x_pos, int *y_pos)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
	{	
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'P')
			{
				*x_pos = width;
				*y_pos = height;
				return ;
			}
			width++;
		}
		height++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	int	width;

	if (y < 0 || map[y] == NULL)
		return ;
	width = ft_strlen(map[y]);
	if (x < 0 || x >= width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == '\n')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char    **map_copy(char **map)
{
    int     height;
    char    **cpy;

    height = 0;
    while (map[height])
        height++;
    cpy = malloc(sizeof(char *) * (height + 1));
    if (!cpy)
        return (NULL);
    height = 0;
    while (map[height])
    {
        cpy[height] = ft_strdup(map[height]);
        if (!cpy[height])
			return (free_map(cpy), NULL);
        height++;
    }
    cpy[height] = NULL;
    return (cpy);
}

int accessible_check(char **map)
{
    int c_found;
    int e_found;
    int height;
    int width;

    height = 0;
    c_found = 0;
    e_found = 0;
    while (map[height])
    {
        width = 0;
        while (map[height][width])
        {
            if (map[height][width] == 'C')
                c_found++;
            else if (map[height][width] == 'E')
                e_found++;
            width++;
        }
        height++;
    }
    if (c_found > 0 || e_found > 0)
        return (0);
    return (1);
}
int valid_path_check(char **map)
{
    char    **map_copied;
    int     x_pos;
    int     y_pos;
    int     result;

    find_player(map, &x_pos, &y_pos);
    map_copied = map_copy(map);
    if (!map_copied)
        return (0);
    flood_fill(map_copied, x_pos, y_pos);
    result = accessible_check(map_copied);
    free_map(map_copied);
    return (result);
}