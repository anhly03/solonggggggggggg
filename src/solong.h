/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:03:16 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 18:37:41 by phly             ###   ########.fr       */
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

int		counter_check(char **map, int *counter_p,
			int *counter_c, int *counter_e);
int		char_check(char **map);
int		shape_check(char **map);
int		check_top_bottom(char *line);
int		wall_check(char **map);
void	find_player(char **map, int *x_pos, int *y_pos);
void	flood_fill(char **map, int x, int y);
char	**map_copy(char **map);
int		accessible_check(char **map);
int		valid_path_check(char **map);
void	destroy_images(t_game *game);
void	cleanup_and_exit(t_game *game);
int		handle_key_esc(int keycode, t_game *game);
int		handle_x_button(t_game *game);
void	get_new_position(int keycode, int *x, int *y);
void	move_player(t_game *game, int new_x, int new_y, char current);
void	exit_handle(t_game *game);
int		key_hook(int keycode, t_game *game);
int		open_map(char *file_name);
void	free_map(char **map);
int		count_map_height(char *file_name);
char	**read_map(char *file_name);
void	init_window(t_game *game);
void	load_image(t_game game);
void	draw_tile(t_game *game, int x, int y);
void	draw_map(t_game *game);

#endif