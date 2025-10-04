/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:21:40 by phly              #+#    #+#             */
/*   Updated: 2025/10/04 20:04:14 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

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

int	main(void)
{
	t_game	game;
	int		y;
	int		w;
	int		h;

	while (game.map[y])
		y++;
	game.height = y;
	game.width = ft_strlen(game.map[0]);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.height * 64, "so_long");
	if (!game.win)
		return (1);
	mlx_loop(game.mlx);
	game.img_wall = mlx_xpm_file_to_image(game.mlx, "img/wall.xpm", &w, &h);
	game.img_coin = mlx_xpm_file_to_image(game.mlx, "img/coin.xmp", &w, &h);
	game.img_exit = mlx_xpm_file_to_image(game.mlx, "img/exit.xmp", &w, &h);
	game.img_ground = mlx_xpm_file_to_image(game.mlx, "img/ground.xmp", &w, &h);
	game.img_player = mlx_xpm_file_to_image(game.mlx, "img/player.xmp", &w, &h);
	return (0);
}

void	draw_map(t_game game)
{
	int	y;
	int	x;
	int	size;

	y = 0;
	size = 64;
	while (game-> map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, )
			x++;
		}
		y++;
	}
}
