/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:53:11 by phly              #+#    #+#             */
/*   Updated: 2025/09/23 19:59:23 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	char	**map;
	int		i;
	char	tile;

	fd = open("file.ber", O_RDONLY);
	if (fd == -1)
		return (printf("Error"));
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close (fd);
	map = malloc(sizeof(char *) *(height + 1));
	if (!map)
		return (printf("Malloc error\n"), 1);
	fd = open("file.ber", O_RDONLY);
	if (fd == -1)
		return (printf("Error"));
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	i = 0;
	while (map[i])
		free(map[i++]);
	free (map);
	//validate map
	i = 0;
	width = 0;
	while (map[height][width])
		width++;
	tile = map[height][width];
	while (map[height][width])
	
	return (0);
}




