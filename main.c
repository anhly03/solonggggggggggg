/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:55:34 by phly              #+#    #+#             */
/*   Updated: 2025/09/24 15:56:16 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	char	**map;
	int		i;

	fd = open("file.ber", O_RDONLY);
	if (fd == -1)
		return (perror(""), 1);
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
		return (perror(""), 1);
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
	if (check_map(map)) //validate map, contains 01CPE or not?
		return (1);
	close (fd);

	return (0);
}