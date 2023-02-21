#include "include/cub.h"
#include <stdio.h>

// int key_hook(int keycode, void *cb)
// {
//     printf("%d\n", keycode);
//     t_cub *cub = (t_cub *)cb;
//     if (keycode == UP)
//     {
//         cub->player->y = (cub->player->y  + (sin(cub->player->retation_angle++) * PLAYER_SPEED));
//         cub->player->x = (cub->player->x  + (cos(cub->player->retation_angle--) * PLAYER_SPEED));
//     }
//     render(cub);

//     return 0;
// }

// void    animation(t_cub *cub)
// {
//     mlx_hook(cub->mlx->mlx_win, 2, 0L, &key_hook, cub);
// }

int main (int argc, char **argv)
{
    t_cub *cub;

	if(check_arguments_available(argc,argv) == -1)
		exit(0);
    if(init_data(&cub, argv[1]) == -1)
	{
		write(1,"Error\n",1);
		exit(0);
	}
    // render(cub);
    // animation(cub);
    // mlx_loop(cub->mlx->mlx);
    return(0);
}