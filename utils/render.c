#include "../include/cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void    mlx_render_cmp(int x, int y, t_cub *cub)
{
    int x_len;
    int y_len;

    x_len = (x * TILE_SIZE) + TILE_SIZE;
    y_len = (y * TILE_SIZE) + TILE_SIZE;
    int x_start = x * TILE_SIZE;
    int y_start = y * TILE_SIZE;
    while ((y_start) < y_len)
    {
        while ((x_start) < x_len && (y_start) < y_len)
        {
            if (cub->data->map[y][x] == '1' || x_start == x_len - 1 || y_start == y_len - 1)
	            my_mlx_pixel_put(cub->img, (x_start), (y_start), 0x8B4513);
            else
				my_mlx_pixel_put(cub->img, x_start, y_start, 0xD1A455);
            x_start++;
        }
        x_start = x * TILE_SIZE;
        y_start++;
    }
}
void render_map(t_cub *cub)
{	
    int	x;
	int y;
    
	x = 0;
	y = 0;
	while(cub->data->map[y])
    {
		while (cub->data->map[y][x])
            mlx_render_cmp(x++, y, cub);
		x = 0;
		y++;
    }
}

void	get_player_index(t_cub *cub)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (cub->data->map[y])
    {
        while (cub->data->map[y][x])
        {
            if (cub->data->map[y][x] == 'P')
            {
                cub->player->x = x * TILE_SIZE + (TILE_SIZE / 2) ;
                cub->player->y = y * TILE_SIZE + (TILE_SIZE / 2) ;
            }
            x++;
        }
        x = 0;
        y++; 
    }
}

void render_player(t_cub *cub)
{
    int player_len_x =  cub->player->x + PLAYER_SIZE;
    int player_len_y =  cub->player->y + PLAYER_SIZE;
    int x = 0;
    int y = 0;
    while (cub->player->y + y - PLAYER_SIZE < player_len_y)
    {
        while (cub->player->x + x - PLAYER_SIZE < player_len_x)
            my_mlx_pixel_put(cub->img, (cub->player->x + x++ - PLAYER_SIZE), (cub->player->y + y - PLAYER_SIZE), 0x0000);
        x = 0;
        y++;
    }
}

void render_ray(t_cub *cub)
{
   int len;

   len = 0;
   while (len < RAY_LEN)
        my_mlx_pixel_put(cub->img, cub->player->x + len++, cub->player->y, 0xFF2D00);
}

void render(t_cub *cub)
{
    render_map(cub);
    render_player(cub);
    render_ray(cub);
    mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->mlx_win, cub->img->img, 0, 0);
}