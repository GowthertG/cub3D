#include "cub3d.h"

void get_player_index(t_cub *cub)
{
    while (cub->map[cub->player->y])
    {
        while (cub->map[cub->player->y][cub->player->x])
        {
            if (cub->map[cub->player->y][cub->player->x] == 'P')
                return ;
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
}