#include "include/cub.h"


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
	return (1);
}
int check_position(char lettre)
{
	if(lettre == 'N')
        return (1);
    else if(lettre =='S')
        return (1);
    else if(lettre == 'E')
        return (1);
    else if(lettre == 'W')
        return (1);
    return (0);
}
int check_available_char(char lettre)
{
	//printf("%c",lettre);
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
	else if (lettre == '\n')
		return (1);
	else if (lettre == ' ')
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
            if(check_available_char(cub->data->map[i][j]) != 1)
				return (-1);
            j++;
        }
        i++;
    }
    return (1);
}
size_t ft_maplen(char **map)
{
    size_t i;

    i = 0;
    while(map[i])
    {
        i++;
    }
    return (i);
}
char *erase_return_line(char *temp)
{
	char *erased;
	int	i;

	i = ft_strlen(temp) - 1;
	erased = (char *)malloc(sizeof(char) * (i + 1));
	if(erased == 0)
		return (0);
	i = 0;
	while(temp[i] && temp[i] != '\n')
	{
		erased[i] = temp[i];
		i++;
	}
	erased[i] ='\0';
	return (erased);
}
int filled_with_1(char **map,int i , int j)
{
	int temp;

	temp = j;
	while(j >=0 && map[i][j])
	{
		if(map[i][j] != '1' || map[i][j] != ' ')
			return (temp);
		if(map[i][j] == '1')
			temp = j;
		j--;
	}
	return (temp);
}
int last_seen_1(char **map,int j)
{
	int	r;
	int	i;
	int	temp;

	r = 0;
	while(map[j][r] == ' ')
		r++;
	i = ft_strlen(map[j]) - 1;
	while(i >= 0)
	{
		if(map[j][i] == '1')
		{
			temp = i;
			temp = filled_with_1(map,j,i);
			return (temp);
		}
		i--;
	}
	return (-1);
}
int last_1(char **map , int j)
{
	int	r;

	r = ft_strlen(map[j]) - 1;
	while(r > 0)
	{
		if(map[j][r] == '1')
			return (r);
		r--;
	}
	return (-1);
}
int first_last_line(t_data *map)
{
    size_t i;
    size_t j;
	int begin_with_space;
	int	found_1;

	i = ft_maplen(map->map);
    j = 0;
	begin_with_space = 0;
	found_1 = 0;
	while(map->map[0][j] && map->map[0][j] == ' ')
	{
		j++;
		begin_with_space = 1;
	}
    while(map->map[0][j])
    {	
        if(map->map[0][j] == '1')
		{
			found_1 = 1;
			j++;
		}
        else if(map->map[0][j] == ' ' && j + 1 != ft_strlen(map->map[0]))
            j++;
        else if(map->map[0][j] == '\n')
			j++;
		else
			return (-1);
    }
	if(found_1 == 0)
		return (-1);
	begin_with_space = 0;
	found_1 = 0;
    i = ft_maplen(map->map) - 1;
    j = 0;
	while(map->map[i][j] && map->map[i][j] == ' ')
	{
		j++;
		begin_with_space = 1;
	}
    while(map->map[i][j])
    {
        if(map->map[i][j] == '1')
        {
			found_1 = 1;
			j++;
		}
        else if(map->map[i][j] == ' ')
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
            return(-1);
        i++;
    }
	i = ft_maplen(map->map) - 1;
	if(map->map[i][0] == '\0')
		return (-1);
    return (1);
}
char ** new_file_matrix(char **file, int r)
{
	int	i;
	int	j;
	int	max;
	char **new_file;

	i = 0;
	max = ft_strlen(file[i]);
	while(file[i])
	{
		if(file[i + 1] && max < (int)ft_strlen(file[i + 1]))
			max = ft_strlen(file[i + 1]);
		i++;
	}
	new_file = (char **)malloc(sizeof(char *) * (i + 1));
	if(new_file == 0)
		return (0);
	j = 0;
	
	while(file[j])
	{
		new_file[j] = (char *)malloc(sizeof(char) * (max + 1));
		if(new_file[j] == 0)
			exit(0);
		r = 0;
		while(file[j][r])
		{
			new_file[j][r] = file[j][r];
			r++;
		}
		if (new_file[j][r - 1] == '\n' && r != max)
			new_file[j][r - 1] = '3';
		while(r < max - 1)
		{
			new_file[j][r] = '2';
			r++;
		}
		if(r == max - 1)
		{
			new_file[j][r] = '\n';
			r++;
		}
		new_file[j][r] = '\0';
		j++;
	}
	new_file[j] = NULL;
	j = 0;
	while(new_file[j])
		printf("%s\n",new_file[j++]);
	return new_file;
}
int check_valid_0(char **map)
{
	size_t	i;
	int	j;
	char **new_file;

	new_file = new_file_matrix(map,0);
	i = 1;
	while(i < ft_maplen(new_file) - 1)
	{
		j = 0;
		while(new_file[i][j])
		{
			if(new_file[i][j] != ' ' && new_file[i][j] != '1' && new_file[i][j] != '2' && new_file[i][j] != '3' && new_file[i][j] != '\n')
			{	
				if(!j || new_file[i][j + 1] == ' ' || new_file[i][j - 1] == ' ' || new_file[i - 1][j] == ' ' || new_file[i + 1][j] == ' ')
					return (-1);
				else if(new_file[i][j + 1] == '3' || new_file[i][j - 1] == '3' || new_file[i + 1][j] == '3' || new_file[i - 1][j] == '3')
					return (-1);
				else if(new_file[i][j + 1] == '2' || new_file[i][j - 1] == '2' || new_file[i + 1][j] == '2' || new_file[i - 1][j] == '2')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
// int check_closed_map_up(char **map , int i)
// {
// 	int	k;

// 	if(ft_strlen(map[i - 1]) > ft_strlen(map[i]))
// 	{
// 		k = last_seen_1(map, i - 1);
// 		if(map[i - 1][k] == '1' || map[i - 1][k + 1] == '1' || map[i - 1][k - 1] == '1')
// 			return (1);
// 	}
// 	if(ft_strlen(map[i - 1 ]) < ft_strlen(map[i]))
// 	{
// 		k = last_seen_1(map,i);
// 		if(map[i][k] == '1' || map[i][k + 1] == '1' || map[i][k - 1] == '1')
// 			return (1);
// 	}
// 	return (-1);
// }
// int check_closed_map_down(char **map , int i)
// {
// 	int	k;

// 	if(ft_strlen(map[i + 1]) > ft_strlen(map[i]))
// 	{
// 		k = last_seen_1(map, i + 1);
// 		if(map[i - 1][k] == '1' || map[i - 1][k - 1] == '1' || map[i - 1][k + 1] == '1')
// 			return (1);
// 	}
// 	if(ft_strlen(map[i + 1]) <ft_strlen(map[i]))
// 	{
// 		k = last_seen_1(map,i);
// 		if(map[i][k] == '1' || map[i][k - 1] == '1' || map[i][k + 1] == '1')
// 			return (1);
// 	}
// 	return (-1);
// }
// int check_closed_map(char **map)
// {
// 	int	i;

// 	i = 1;
// 	while(i < (int)ft_maplen(map) - 1)
// 	{
// 		if(check_closed_map_down(map,i) == -1)
// 			return(-1);
// 		if(check_closed_map_down(map,i) == -1)
// 			return (-1);
// 		i++;
// 	}
// 	return (1);
// }
int check_duplicate(char **map)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(check_position(map[i][j]) && found == 0)
				found = 1;
			else if(check_position(map[i][j]) && found)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
int check_required_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(check_position(map[i][j]))
			{
				if(check_duplicate(map) == -1)
					return (-1);
				else
					break;
			}
			j++;
		}
		i++;
	}
	return(1);
}
int check_map(t_cub *cub)
{
    if (check_char_map(cub) == -1)
    {
        write(1,"Bad Map\n",8);
        return (-1);
    }
    int     i;

    i = 1;
    if (ft_maplen(cub->data->map) < 3)
        return (-1);
	if (check_return_line(cub->data) == -1)
		return (-1);
    if(first_last_line(cub->data) == -1)
    	return (-1);
	if (check_valid_0(cub->data->map) == -1)
		return (-1);
	// if(check_closed_map(cub->data->map) == -1)
	// 	return  (-1);
	// if(check_required_character(cub->data->map) == -1)
	// 	return (-1);
	return (1);
}