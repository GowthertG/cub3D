#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
// keycode

# define UP		13
# define DOWN	1
# define RIGHT	0
# define LEFT	2

//to read from map


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
void	render(t_cub *cub);
void	render_map(t_cub *cub);
void	get_player_index(t_cub *cub);

//render
t_cub	*alloc(void);
char	**get_map(char *filename);
int		init_data(t_cub **cub, char *argv);
void	mlx_render_cmp(int x, int y, t_cub *cub);


// Parsing
int		check_arguments_available(int argc,char **argv);
int		index_last(char **file);
int 	fill_map(char **file , t_cub *cub);
int 	is_all_textures_available(char **file);
int 	is_all_rgb_available(char ** file);
int 	is_duplicated(char **file , char *s);
int 	duplicate_textures(char **file);
int 	duplicate_RGB(char **file);
int 	ft_researchstring(char **files , char *s, int position);
int 	fill_textures(char **files, t_cub *cub);
int 	fill_RGB(char **files , t_cub *cub);
int 	valid_map(t_cub *cub);
int 	check_position(char lettre);
int 	check_available_char(char lettre);
int 	check_char_map(t_cub *cub);
size_t 	ft_maplen(char **map);
int 	check_block_lower(char **map);
int 	check_block_higher(char **map , int r);
int 	first_last_line(t_data *map);
int 	check_return_line(t_data *map);
int 	check_valid_0(char **map);
int 	check_duplicate(char **map);
int 	check_required_character(char **map);
int 	check_map(t_cub *cub);
int 	ft_ctoi(char c);
int 	check_rgb(t_cub *cub , int i);
int 	parse_rgb(t_cub *cub);
int 	check_textures_part1(t_cub *cub, int *pos);
int 	check_correct_name(char **textures, int *pos , int j);
int 	check_textures_part2(t_cub *cub, int *pos);
int 	check_textures(t_cub *cub);
int		max_cols(char **map);
#endif