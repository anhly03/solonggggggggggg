/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:21:40 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 19:03:15 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "libftprintf.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long <map.ber>\n"), 1);
	game.map = read_map(argv[1]);
	if (!game.map || !map_check(game.map))
		return (free_map(game.map), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (perror("MLX init failed"), 1);
	game.win = mlx_new_window(game.mlx,
			ft_strlen(game.map[0]) * 64,
			count_map_height(game.map) * 64,
			"So Long");
	load_image(&game);
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, handle_x_button, &game);
	mlx_loop(game.mlx);
	return (0);
}

