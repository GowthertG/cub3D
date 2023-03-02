#include "../include/cub.h"

char **read_file(char *filename)
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
    cub = (t_cub *)malloc(sizeof(t_cub));
	if(cub == 0)
		return (NULL);
    cub->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if(cub->mlx == 0)
		return (NULL);
    cub->player = (t_player *)malloc(sizeof(t_player));
	if(cub->player == 0)
		return (NULL);
    cub->data = (t_data *)malloc(sizeof(t_data));
	if(cub->data == 0)
		return (NULL);
    cub->img = (t_img *)malloc (sizeof(t_img));
	if(cub->img == 0)
		return (NULL);
    return(cub);
}
int max_cols(char **map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while(map[i])
	{
		i++;
		j = 0;
		while(map[i][j])
			j++;
		if(max < j)
			max = j;
		i++;
	}
	return (max);
}
int len_file(char *fl)
{
	int	i;
	int	fd;

	fd = open(fl,O_RDONLY);
	if(fd < 0)
		return (-1);
	i = 0;
	while(get_next_line(fd))
		i++;
	return (i);
}
int init_data(t_cub **cub, char *fl)
{
	int	fd;
	int	i;
	char **file;
	int	j;
	char *temp;

	j = 1;
	i = len_file(fl);

	fd = open(fl,O_RDONLY);
	if(fd < 0)
		return (-1);
	file = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	temp = get_next_line(fd);
	while(temp)
	{
		file[i] = ft_strdup(temp);
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	close(fd);
  	*cub = alloc();
	// if(fill_map(file,*cub) == -1)
	// 	return (-1);
	// if(check_map(*cub) == -1)
	// 	return (-1);
	if(fill_RGB(file,*cub) == -1)
		return (-1);
	// if(fill_textures(file,*cub) == -1)
	// 	return (-1);
	// i = ft_maplen((*cub)->data->map);
	// j = max_cols((*cub)->data->map);
    (*cub)->mlx->mlx = mlx_init();
    (*cub)->mlx->mlx_win = mlx_new_window((*cub)->mlx->mlx, i * TILE_SIZE, j * TILE_SIZE, "cub3D");
    (*cub)->img->img = mlx_new_image((*cub)->mlx->mlx, i * TILE_SIZE , j * TILE_SIZE);
	(*cub)->img->addr = mlx_get_data_addr((*cub)->img->img, &(*cub)->img->bits_per_pixel, &(*cub)->img->line_length,
			&(*cub)->img->endian);
    //get_player_index(*cub);
	return (1);
}