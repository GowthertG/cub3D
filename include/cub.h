#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

// keycode

# define UP		13
# define DOWN	1
# define RIGHT	0
# define LEFT	2

//to read from map

# define BUFFER_SIZE	1000

# define PLAYER_SPEED	4
# define TILE_SIZE		32
# define MAP_NUM_ROWS	15
# define MAP_NUM_COLS	11
# define RETATION_SPEED	2
# define PLAYER_SIZE	4
# define RAY_LEN		TILE_SIZE / 2

# define WINDOW_WIDTH (MAP_NUM_ROWS * TILE_SIZE)
# define WINDOW_HEIGHT  (MAP_NUM_COLS * TILE_SIZE)

typedef struct s_img
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}   t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_data
{
	char    **map;
    int     x;
    int     y;
    char    **textures;
    char    **RGB;
} t_data;

typedef struct s_player
{
    double	x;
    double	y;
	double	rotation_angle;
}	t_player;

typedef struct s_cub
{
    t_mlx		*mlx;
    t_player	*player;
    t_data      *data;
    t_img       *img;
}	t_cub;


//utils
void render(t_cub *cub);
void render_map(t_cub *cub);
void     get_player_index(t_cub *cub);

//render
t_cub *alloc(void);
char **get_map(char *filename);
void init_data(t_cub **cub);
void    mlx_render_cmp(int x, int y, t_cub *cub);

#endif