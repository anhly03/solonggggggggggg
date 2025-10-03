#include "mlx.h"

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Hello MLX");
    mlx_loop(mlx);
    return (0);
}