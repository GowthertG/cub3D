#include "../include/cub.h"

char **get_map(char *filename)
{
  char *buffer;
  int fd;
  int index;

  buffer = malloc (BUFFER_SIZE);
  fd = open(filename, O_RDWR);
  index = read(fd, buffer, BUFFER_SIZE);
  buffer[index] = '\0';
  return(ft_split(buffer, '\n'));
}

t_cub   *alloc(void)
{
    t_cub *cub;
    cub = malloc(sizeof(t_cub));
    cub->mlx = malloc(sizeof(t_mlx));
    cub->player = malloc(sizeof(t_player));
    cub->data = malloc(sizeof(t_data));
    cub->img = malloc (sizeof(t_img));
    return(cub);
}

void init_data(t_cub **cub)
{
    (*cub) = alloc();
    (*cub)->data->map = get_map("map/map");
    (*cub)->mlx->mlx = mlx_init();
    (*cub)->mlx->mlx_win = mlx_new_window((*cub)->mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
    (*cub)->img->img = mlx_new_image((*cub)->mlx->mlx, MAP_NUM_ROWS * TILE_SIZE , MAP_NUM_COLS * TILE_SIZE);
	  (*cub)->img->addr = mlx_get_data_addr((*cub)->img->img, &(*cub)->img->bits_per_pixel, &(*cub)->img->line_length,
			&(*cub)->img->endian);
    get_player_index(*cub);
}