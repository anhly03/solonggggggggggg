/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:55:34 by phly              #+#    #+#             */
/*   Updated: 2025/10/05 18:01:12 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_check(char **map)
{
	if (!(counter_check && char_check && wall_check && shape_check))
		return (perror(""), 0);
	return (1);
}

int	open_map(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Open map failed");
		return (-1);
	}
	return (fd);
}
int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
int	read_map(t_game *game, char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	fd = open_map(file_name);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	game->height = 0;
	while (line != NULL)
	{
		free(line);
		game->height++;
		line = get_next_line(fd);
	}
	close (fd);
	game->map = malloc(sizeof(char *) *(game->height + 1));
	if (!game->map)
		return (printf("Malloc error\n"), 1);
	fd = open_map(file_name);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close (fd);
	if (!(map_check(game->map)))
		return (free (game->map), 1);
	return (0);
}
