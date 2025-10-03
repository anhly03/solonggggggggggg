/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:53:11 by phly              #+#    #+#             */
/*   Updated: 2025/09/24 15:55:32 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_allowed(char c)
{
	char	*allowed;
	int		i;

	allowed = "01CPE\n";
	i = 0;
	while (allowed[i])
		if (c == allowed[i++])
			return (1);
	return (0);
}

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
				*(counter_p)++;
			else if (map[height][width] == 'C')
				*(counter_c)++;
			else if (map[height][width] == 'E')
				*(counter_e)++;
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
	int	height;
	int	width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] != '\n' && !is_allowed(map[height][width]))
				return (perror("Invalid character in map:"), 0);
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

	height = 0;
	width_len = ft_strlen(map[0]) - 1;
	while (map[height])
	{
		if (((int)ft_strlen(map[height]) - 1) != width_len)
			return(perror("Map is not rectangle"), 0);
		height++;
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
	while (map[height - 1][width] && map[height][width] != '\n')
		if (map[height - 1][width++] != '1')
			return (perror("Invalid wall:"), 0);
	i = 1;
	len = ft_strlen(map[height]) - 1;
	while (i < (height - 1))
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (perror("Invalid wall:"), 0);
		i++;
	}
	return (1);
}

int	map_check(char **map)
{
	if (!(counter_check && char_check && wall_check && shape_check))
		return (perror(""), 0);
	return (1);
}


