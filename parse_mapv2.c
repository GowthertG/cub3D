#include "../../include/cub.h"


int valid_map(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while(i < cub->data->y)
    {
        j = 0;
        while(j < cub->data->x)
        {
            if(cub->data->map[i][j] != '1' && i == 0)
                return (-1);
            else if(cub->data->map[i][j] != '1' && i == cub->data->y - 1)
                return(-1);
            else if(cub->data->map[i][j] != '1' && i == cub->data->y - 1)
                return(-1);
        }
    }
}
int check_available_char(char lettre)
{
    if(lettre == '1')
        return (1);
    else if(lettre == '0')
        return(1);
    else if(lettre == 'N')
        return (1);
    else if(lettre =='S')
        return (1);
    else if(lettre == 'E')
        return (1);
    else if(lettre == 'W')
        return (1);
    return (0);
}
int check_char_map(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while(cub->data->map[i])
    {
        j = 0;
        while(cub->data->map[i][j])
        {
            if(check_available_char(cub->data->map[i][j]) == 0)
                return(-1);
            j++;
        }
        i++;
    }
    return (-1);
}
int ft_maplen(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        i++;
    }
    return (i);
}
int check_block_lower(char **map)
{
	int	i;

	if(ft_strlen(map[0]) > ft_strlen(map[1]))
	{
		i = fstrlen(map[1]);
		if ((map[1][i - 1] || map[1][i - 1] != '1' ) && (map[1][i -2] || map[1][i - 2] != '1' ) && ( map[1][i -2] || map[1][i] != '1'))
			return (-1);
		return (1);
	}
	else
	{
		i = ftstrlen(map[0]);
		if ((map[1][i - 1] || map[1][i - 1] != '1' ) && (map[1][i -2] || map[1][i - 2] != '1' ) && ( map[1][i -2] || map[1][i] != '1'))
			return (-1);
		return (1);
	}
	return (1);
}

int check_block_higher(char **map , int r)
{
	int	i;

	if(ft_strlen(map[r]) > ft_strlen(map[r - 1]))
	{
		i = fstrlen(map[r - 1]) - 1;
		if ((map[i - 1][r] || map[i - 1][r] != '1' ) && (map[i - 1][r - 1] || map[i - 1][r - 1] != '1' ) && ( map[i - 1][r + 1] || map[i - 1][r + 1] != '1'))
			return (-1);
		return (1);
	}
	else
	{
		i = ftstrlen(map[r]) - 1;
		if ((map[i - 1][r] || map[i - 1][r] != '1' ) && (map[i - 1][r - 1] || map[i - 1][r - 1] != '1' ) && ( map[i - 1][r + 1] || map[i - 1][r + 1] != '1'))
			return (-1);
		return (1);
	}
	return (1);
}
int first_last_line(t_data *map)
{
    int i;
    int j;
	int begin_with_space;

	i = ft_maplen(map->map);
    j = 0;
	begin_with_space = 0;
	while(map->map[0][j] && map->map[0][j] == ' ')
	{
		j++;
		begin_with_space = 1;
	}
    while(map->map[0][j])
    {
        if(map->map[0][j] == '1')
        {
			if((j == 0 && (map->map[1][j] != '1' && map->map[1][j + 1] != '1')) || (begin_with_space == 1 && (map->map[1][j] != '1' && map->map[1][j + 1] != '1' && map->map[1][j - 1] != '1')))
				return (-1);
			else if (ft_strlen(map->map[1]) < ft_strlen(map->map[0]) && j != 0)
			{
				if((j + 1) != ft_strlen(map->map[1]))
					j++;
			}
			else if (ft_strlen(map->map[1]) >= ft_strlen(map->map[0]) && j != 0)
			{
				if((j + 1) != ft_strlen(map->map[0]))
					j++;
			}
			else if(check_block_lower(map->map) == -1)
				return (-1);
		}
        else if(map->map[0][j] == ' ' && j + 1 != ft_strlen(map->map[0]))
            j++;
        else
			return (-1);
    }
	begin_with_space = 0;
    i = ft_maplen(map->map) - 1;
    j = 0;
	while(map->map[0][j] && map->map[0][j] == ' ')
	{
		j++;
		begin_with_space = 1;
	}
    while(map->map[i][j])
    {
        if(map->map[i][j] == '1')
        {
			if((j == 0 && (map->map[i - 1][j] != '1' && map->map[i - 1][j + 1] != '1')) || (begin_with_space == 1 && (map->map[i - 1][j] != '1' && map->map[i - 1][j + 1] != '1' && map->map[i - 1][j - 1] != '1')))
				return (-1);
			else if (ft_strlen(map->map[i]) < ft_strlen(map->map[i - 1]) && j != 0)
			{
				if((j + 1) != ft_strlen(map->map[i]))
					j++;
			}
			else if (ft_strlen(map->map[i]) >= ft_strlen(map->map[i - 1]) && j != 0)
			{
				if((j + 1) != ft_strlen(map->map[i - 1]))
					j++;
			}
			else if(check_block_higher(map->map,i) == -1)
				return (-1);
		}
        else if(map->map[i][j] == ' ' && j + 1 != ft_strlen(map->map[0]))
            j++;
		else
        	return (-1);
    }
    return (1);
}
int check_return_line(t_data *map)
{
    int i;

    i = 0;
    while(map->map[i])
    {
        if(map->map[i][0] == '\n')
            return(0);
        i++;
    }
    return (1);
}

int check_valid_0(char **map)
{
	int	i;
	int	j;

	i = 1;
	while(i < ft_maplen(map) - 1)
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != ' ' || map[i][j] != '1')
			{	
				if(map[i][j + 1] == ' ' || map[i][j - 1] == ' '
                    || map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					return (-1);
				else if((map[i][j + 1] == '\n' || map[i][j - 1] == '\n'
                    || map[i + 1][j] == '\n' || map[i - 1][j] == '\n'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int check_map(t_cub *cub)
{
    if (check_char_map(cub) == -1)
    {
        write(1,"Bad Map\n",8);
        return (-1);
    }
    int     i;
    int     j;
    char    s;

    i = 1;
    if (ft_maplen(cub->data->map) < 3)
        return (-1);
	if (check_return_line(cub->data) == 0)
		return (-1);
    if(first_last_line(cub->data) == -1)
    	return (-1);
	if (check_valid_0(cub->data->map) == -1)
		return (-1);
}