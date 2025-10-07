/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:34:47 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 16:41:13 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	init_window(t_game *game)
{
	int	img_w;
	int	img_h;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "So Long!");
	if (!game->win)
		exit(1);
}

void	load_image(t_game game)
{
	int	w;
	int	h;

	game.img_wall = mlx_xpm_file_to_image(game.mlx, "img/wall.xpm", &w, &h);
	game.img_coin = mlx_xpm_file_to_image(game.mlx, "img/coin.xpm", &w, &h);
	game.img_exit = mlx_xpm_file_to_image(game.mlx, "img/exit.xpm", &w, &h);
	game.img_ground = mlx_xpm_file_to_image(game.mlx, "img/ground.xpm", &w, &h);
	game.img_player = mlx_xpm_file_to_image(game.mlx, "img/player.xpm", &w, &h);
}

void	draw_tile(t_game *game, int x, int y)
{
	int	size;

	size = 64;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * size, y * size);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_ground, x * size, y * size);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_coin, x * size, y * size);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * size, y * size);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x * size, y * size);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 		return (ft_putendl_fd("Usage: ./so_long map.ber", 2), 1);
// 	game.map = read_map(argv[1]); // bạn đã viết sẵn phần này ở bước trước
// 	game.width = ft_strlen(game.map[0]);
// 	game.height = 0;
// 	while (game.map[game.height])
// 		game.height++;
// 	init_window(&game);
// 	load_images(&game);
// 	render_map(&game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }

//da check voi gpt