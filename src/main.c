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
	/* 
	* Goal : 
			G1) write a separate file importing a library and return a game object for use.
			G2) use G1 to display first image
			G3) based on G2, extend the function to react on 'A', 'S', 'W', 'D'
			G4) define the end game scenario and its condition
			G5) implement the algorithm to detect entering the G4. End program.
	* TODO :
			G1) 
			   TG1.1) create new file
			   TG1.2) include the library and test build the file with dummy usage
			   TG1.3) extend the dummy , using real functional

			G2) ...

	
	*/







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
	// TG1.1
		return (1);
	load_image(game);
	draw_map(&game);
	// TG1.2
	mlx_loop(game.mlx);
	return (0);
}
