#ifndef CUB3D_H
                            # define CUB3D_H

            # include <unistd.h>
        # include <mlx.h>
        # include "libft.h"
        #include <unistd.h>
        #include <fcntl.h>

#define	TILE_SIZE  32
#define MAP_NUM_ROWS  15
#define MAP_NUM_COLS  11

#define WINDOW_WIDTH (MAP_NUM_ROWS * TILE_SIZE)
#define WINDOW_HEIGHT  (MAP_NUM_COLS * TILE_SIZE)
typedef struct s_player
{
    int x;
    int y;
} t_player ;

typedef struct s_cub
{
    char **map;
    void *mlx;
    void *win;
    t_player *player;
} t_cub;

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

// init cub struct
void    init_data(t_cub **cub);
// get player x and y
void get_player_index(t_cub *cub);
// render minimap 
void	render(t_cub *cub);
void	put_pixel_to_image(t_cub *cub, int x, int y, t_data *img);
// faster pixel_put
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//
char ** get_map();

#endif
