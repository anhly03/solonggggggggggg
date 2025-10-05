/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:03:16 by phly              #+#    #+#             */
/*   Updated: 2025/10/05 18:18:41 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	void	*img_ground;
	char	**map;
	int		width;
	int		height;
}	t_game;

int	is_allowed(char c);
int	counter_check(char **map, int *counter_p, int *counter_c, int *counter_e);
int	char_check(char **map);
int	shape_check(char **map);
int	wall_check(char **map);

#endif