/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:55:34 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 16:31:37 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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

char	**read_map(char *file_name)
{
	int		fd;
	char	*line;
	t_game	game;

	game.height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), NULL);
	while ((line = get_next_line(fd)))
	{
		game.height++;
		free(line);
	}
	close(fd);
	game.map = malloc(sizeof(char*) * (game.height + 1));
	if (!game.map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), NULL);
	game.height = 0;
	while ((line = get_next_line(fd)))
		game.map[game.height++] = line;
	game.map[game.height] = NULL;
	close (fd);
	return (game.map);
}




