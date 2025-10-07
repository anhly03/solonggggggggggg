/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:55:34 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 18:32:30 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "get_next_line.h"

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

void	free_map(char **map)
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

int	count_map_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	**read_map(char *file_name)
{
	int		fd;
	int		height;
	int		i;
	char	*line;
	char	**map;

	height = count_map_height(file_name);
	if (height <= 0)
		return (perror("Invalid map file"), NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error reopening file"), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	return (map);
}


//tam xong



