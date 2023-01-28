#include "cub3d.h"
#include <stdlib.h>
void get_player_index(t_cub *cub)
{
    cub->player->x = 0;
    cub->player->y = 0;
    while (cub->map[cub->player->y])
    {
        while (cub->map[cub->player->y][cub->player->x])
        {
            if (cub->map[cub->player->y][cub->player->x] == 'P')
                {
                    cub->player->x*=32;
                    cub->player->y*=32;
                    return ;
                }
            cub->player->x++;
        }
       cub->player->x = 0;
       cub->player->y++; 
    }
}

void    init_data(t_cub **cub)
{
    *cub = malloc(sizeof(t_cub));
    (*cub)->player = malloc(sizeof(t_player));
    (*cub)->mlx = mlx_init();
    (*cub)->map = get_map();
    get_player_index(*cub);

}