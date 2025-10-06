#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;
	char	current;

	new_x = game->x_pos;
	new_y = game->y_pos;
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	else if (keycode == KEY_ESC)
		exit(0);
	current = game->map[new_y][new_x];
	if (current == '1')
		return (0);
	if (current == '0' || current == 'C')
	{
		if (next == 'C')
			game->c_count--;
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos = new_x;
		game->y_pos = new_y;
		game->map[new_y][new_x] = 'P';
		game->steps++;
		ft_prinft("Steps: %d\n", game->steps);
	}
	else if (current == 'E')
	{
		if (game->c_count == 0)
		{
			ft_printf("You win! Total steps: %d\n", game->steps);
			exit(0);
		}
		else
			ft_printf("Collect all C before exiting\n");
	}
	return (0);
}
