/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:53:11 by phly              #+#    #+#             */
/*   Updated: 2025/10/05 18:27:33 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	counter_check(char **map, int *counter_p, int *counter_c, int *counter_e)
{
	int		height;
	int		width;

	*counter_p = 0;
	*counter_c = 0;
	*counter_e = 0;
	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'P')
				(*counter_p)++;
			else if (map[height][width] == 'C')
				(*counter_c)++;
			else if (map[height][width] == 'E')
				(*counter_e)++;
			width++;
		}
		height++;
	}
	if (!(*counter_p == 1 && *counter_c >= 1 && *counter_e == 1))
		return (perror("Invalid number of P/C/E"), 0);
	return (1);
}

int	char_check(char **map)
{
	int		height;
	int		width;
	int		i;
	char	*allowed;
	int		check;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			i = 0;
			check = 0;
			while (allowed[i])
				if (map[height][width] == allowed[i++])
					check = 1;
			if (!check && map[height][width] != '\n')
				return (perror("Invalid character"), 0);
			width++;
		}
		height++;
	}
	return (1);
}

int	shape_check(char **map)
{
	int	height;
	int	width;
	int	width_len;
	int	current_len;

	height = 0;
	width_len = ft_strlen(map[0]);
	while (map[height])
	{
		current_len = ft_strlen(map[height]);
		if (map[height][current_len - 1] == '\n')
			current_len--;
		if (map[0][width_len - 1] == '\n')
			width_len--;
		if (current_len != width_len)
			return (perror("Map is not rectangle"), 0);
		height++;
	}
	return (1);
}

int	check_top_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (perror("Invalid wall"), 0);
		i++;
	}
	return (1);
}

int	wall_check(char **map)
{
	int	height;
	int	width;
	int	i;
	int	len;

	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		if (map[0][width++] != '1')
			return (perror("Invalid wall:"), 0);
	width = 0;
	while (map[height - 1][width] && map[height - 1][width] != '\n')
		if (map[height - 1][width++] != '1')
			return (perror("Invalid wall:"), 0);
	len = ft_strlen(map[0]);
	if ((map[0][len - 1]) == '\n')
		len--;
	i = 1;
	while (i < (height - 1))
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (perror("Invalid wall:"), 0);
		i++;
	}
	return (1);
}

