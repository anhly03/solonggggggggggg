/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:21:40 by phly              #+#    #+#             */
/*   Updated: 2025/10/05 17:43:19 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	int		size;

	y = 0;
	size = 64;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
					x * size, y * size);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_ground,
					x * size, y * size);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_coin,
					x * size, y * size);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					x * size, y * size);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					x * size, y * size);
			x++;
		}
		y++;
	}
}

void	load_image(t_game game)
{
	game.img_wall = mlx_xpm_file_to_image(game.mlx, "img/wall.xpm", &w, &h);
	game.img_coin = mlx_xpm_file_to_image(game.mlx, "img/coin.xpm", &w, &h);
	game.img_exit = mlx_xpm_file_to_image(game.mlx, "img/exit.xpm", &w, &h);
	game.img_ground = mlx_xpm_file_to_image(game.mlx, "img/ground.xpm", &w, &h);
	game.img_player = mlx_xpm_file_to_image(game.mlx, "img/player.xpm", &w, &h);
}

int	main(void)
{
	t_game	game;
	int		y;
	int		w;
	int		h;

	if (read_map(&game, map.ber))
		return (1);
	y = 0;
	while (game.map[y])
		y++;
	game.height = y;
	game.width = ft_strlen(game.map[0]);
	if (game.map[0][game.width - 1] == '\n')
		game.width--;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.height * 64, "so_long");
	if (!game.win)
		return (1);
	load_image(game);
	draw_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
