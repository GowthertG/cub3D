#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_cub
{
    char **map;
    void *mlx;
    void *win;
    void *img;
    int  x;
    int  y;
} t_cub;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
