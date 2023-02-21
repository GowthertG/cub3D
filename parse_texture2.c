#include "include/cub.h"

int check_textures_part1(t_cub *cub, int *pos)
{
    int j;
    int begin;
    int stop;
    int fd;
    char *temp;

	j = 0;
	while(cub->data->textures[*pos][0] == ' ')
		j++;
	if(check_correct_name(cub->data->textures,pos,j) == -1)
		return (-1);
	if(cub->data->textures[*pos][j] != ' ')
		return (-1);
    if(cub->data->textures[*pos][j] == 'N' && cub->data->textures[*pos][j + 1] == 'O')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] == ' ')
            j++;
        begin = j;
        while(cub->data->textures[*pos][j] && cub->data->textures[*pos][j] != ' ')
        {
                stop += 1;
                j++;
        }
        if(cub->data->textures[*pos][j] == ' ')
            return (-1);
        else
        {
            temp = ft_substr(cub->data->textures[*pos], begin, stop);
            fd = open(temp,O_RDONLY);
            if(fd == -1)
            {
                free(temp);
                return (-1);
            }
            // what should i do with the textures
            close(fd);
            free(temp);
        }
    }
    if(cub->data->textures[*pos][j] == 'S' && cub->data->textures[*pos][j + 1] == 'O')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
		if(cub->data->textures[*pos][j] != ' ')
			return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] == ' ')
            j++;
        begin = j;
        while(cub->data->textures[*pos][j] && cub->data->textures[*pos][j] != ' ')
        {
                stop += 1;
                j++;
        }
        if(cub->data->textures[*pos][j] == ' ')
            return (-1);
        else
        {
            temp = ft_substr(cub->data->textures[*pos], begin, stop);
            fd = open(temp,O_RDONLY);
            if(fd == -1)
            {
                free(temp);
                return (-1);
            }
            // what should i do with the textures
            close(fd);
            free(temp);
        }
    }
    return(1);
}
int check_correct_name(char **textures, int *pos , int j)
{
	if(textures[*pos][j] == 'W' && textures[*pos][j + 1] == 'E')
		return (1);
	else if (textures[*pos][j] == 'S' && textures[*pos][j + 1] == 'O')
		return (1);
	else if (textures[*pos][j] == 'E' && textures[*pos][j + 1] == 'A')
		return (1);
	else if (textures[*pos][j] == 'N' && textures[*pos][j + 1] == 'O')
		return (1);
	return (-1);
}
int check_textures_part2(t_cub *cub, int *pos)
{
    int j;
    int begin;
    int stop;
    int fd;
    char *temp;

	j = 0;
	while(cub->data->textures[*pos][0] == ' ')
		j++;
	if(check_correct_name(cub->data->textures,pos,j) == -1)
		return (-1);
    if(cub->data->textures[*pos][j] == 'W' && cub->data->textures[*pos][j + 1] == 'E')
    {
        stop = 0;
        j += 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
		if(cub->data->textures[*pos][j] != ' ')
			return (-1);
        while(cub->data->textures[*pos][j] && cub->data->textures[*pos][j] == ' ')
            j++;
        begin = j;
        while(cub->data->textures[*pos][j] && cub->data->textures[*pos][j] != ' ')
        {
                stop += 1;
                j++;
        }
        if(cub->data->textures[*pos][j] == ' ')
            return (-1);
        else
        {
            temp = ft_substr(cub->data->textures[*pos], begin, stop);
            fd = open(temp,O_RDONLY);
            if(fd == -1)
            {
                free(temp);
                return (-1);
            }
            // what should i do with the textures
            close(fd);
            free(temp);
        }
    }
    if(cub->data->textures[*pos][j] == 'E' && cub->data->textures[*pos][j + 1] == 'A')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
		if(cub->data->textures[*pos][j] != ' ')
			return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] == ' ')
            j++;
        begin = j;
        while(cub->data->textures[*pos][j] && cub->data->textures[*pos][j] != ' ')
        {
                stop += 1;
                j++;
        }
        if(cub->data->textures[*pos][j] == ' ')
            return (-1);
        else
        {
            temp = ft_substr(cub->data->textures[*pos], begin, stop);
            fd = open(temp,O_RDONLY);
            if(fd == -1)
            {
                free(temp);
                return (-1);
            }
            // what should i do with the textures
            close(fd);
            free(temp);
        }
    }
    return(1);
}
int check_textures(t_cub *cub)
{
    int i = 0;
    while(cub->data->textures[i])
    {
        if(check_textures_part1(cub,&i) == -1)
            return (-1);
        if(check_textures_part2(cub,&i) == -1)
            return (-1);
        i++;
    }
    return (1);
}