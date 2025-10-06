#include "mlx.h"
#include "solong.h"

void    destroy_images(t_game *game)
{
    if (game->img_coin)
        mlx_destroy_image(game->mlx, game->img_coin);
    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_ground)
        mlx_destroy_image(game->mlx, game->img_ground);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
}

void    cleanup_and_exit(t_game *game)
{
    free_map(game);
    destroy_image(game);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    exit(0);
}

int handle_key_esc(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        cleanup_and_exit(game);
    return (1);
}

int handle_x_button(t_game *game)
{
    cleanup_and_exit(game);
    return (0);
}