#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	put_pixel_to_image(t_cub *cub, int x, int y, t_data *img)
{
	int	index[2];

	index[0] = y;
	index[1] = x;
	while (y < index[0] + TILE_SIZE && cub->map[index[0] / 32][index[1] / 32])
	{
		while (x < index[1] + TILE_SIZE && cub->map[index[0] / 32][index[1] / 32])
		{
			if (cub->map[index[0] / 32][index[1] / 32] == '1')
				my_mlx_pixel_put(img, x, y, 0x8B4513);
			else
			{
				if (x != index[1] + TILE_SIZE - 1 && y != index[0] + TILE_SIZE - 1)
					my_mlx_pixel_put(img, x, y, 0xD1A455);
				else
					my_mlx_pixel_put(img, x, y, 0x8B4513);
			}
			x++;
		}
		x = index[1];
		y++;
	}
}
void	render(t_cub *cub)
{
	int		x;
	int		y;
	t_data	*img;

	x = 0;
	y = 0;
	img = malloc (sizeof (t_data));
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH , WINDOW_HEIGHT, "cub3d");
	img->img = mlx_new_image(cub->mlx, MAP_NUM_ROWS * 32 , MAP_NUM_COLS * 32);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
			&img->endian);

	int i;

	i = 0;
  while (cub->map[y])
  {
    while (cub->map[y][x])
	{
		printf ("%d\n", y);
       put_pixel_to_image(cub, x * 32, y * 32, img);
	  x++;
	  	// if (y == 10 && x == 15)
		// break ;
	}
	// if (y == 10 && x == 15)
	// 	break ;
	x = 0;
    y++;
  }
  mlx_put_image_to_window(cub->mlx, cub->win, img->img, 0, 0);
}

char ** get_map()
{
  char *buffer;
  int fd;
  int index;

  buffer = malloc (1299);
  fd = open("map", O_RDWR);
  index = read(fd, buffer, 1299);
  buffer[index] = '\0';
  return(ft_split(buffer, '\n'));
}
