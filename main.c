#include "include/cub.h"
#include <stdio.h>

int key_hook(int keycode, void *cb)
{
    printf("%d\n", keycode);
    t_cub *cub = (t_cub *)cb;
    if (keycode == UP)
    {
        cub->player->y = (cub->player->y  + (sin(cub->player->retation_angle++) * PLAYER_SPEED));
        cub->player->x = (cub->player->x  + (cos(cub->player->retation_angle--) * PLAYER_SPEED));
    }
    render(cub);

    return 0;
}

void    animation(t_cub *cub)
{
    mlx_hook(cub->mlx->mlx_win, 2, 0L, &key_hook, cub);
}

int main ()
{
    t_cub *cub;

    init_data(&cub);
    render(cub);
    animation(cub);
    mlx_loop(cub->mlx->mlx);
    return(0);
}