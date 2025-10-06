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

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

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
	int		x_pos;
	int		y_pos;
	int		c_count;
	int		steps;
}	t_game;

int	counter_check(char **map, int *counter_p, int *counter_c, int *counter_e);
int	char_check(char **map);
int	shape_check(char **map);
int	wall_check(char **map);

#endif