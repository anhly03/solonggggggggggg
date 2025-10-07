/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:27:59 by phly              #+#    #+#             */
/*   Updated: 2025/10/07 18:35:02 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	get_new_position(int keycode, int *x, int *y)
{
	if (keycode == KEY_W)
		(*y)--;
	else if (keycode == KEY_S)
		(*y)++;
	else if (keycode == KEY_A)
		(*x)--;
	else if (keycode == KEY_D)
		(*x)++;
}

void	move_player(t_game *game, int new_x, int new_y, char current)
{
	if (current == 'C')
		game->c_count--;
	game->map[game->y_pos][game->x_pos] = '0';
	game->y_pos = new_y;
	game->x_pos = new_x;
	game->map[new_y][new_x] = 'P';
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
	draw_map(game);//code nay la gi zay troi
}

void	exit_handle(t_game *game)
{
	if (game->c_count == 0)
	{
		ft_printf("You win! Total steps: %d\n", game->steps);
		exit(0);
	}
	else
		ft_printf("Collect all coins before exiting\n");
}

int	key_hook(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;
	char	current;

	if (keycode == KEY_ESC)
		exit(0);
	new_x = game->x_pos;
	new_y = game->y_pos;
	get_new_position(keycode, &new_x, &new_y);
	current = game->map[new_y][new_x];
	if (current == '1')
		return (0);
	if (current == '0' || current == 'C')
		move_player(game, new_x, new_y, current);
	else if (current == 'E')
		exit_handle(game);
	return (0);
}
//tam xong voi gpt, da add vao header
