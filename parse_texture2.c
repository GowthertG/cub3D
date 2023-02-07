#include "../../include/cub.h"

int check_textures_part1(t_cub *cub, int *pos)
{
    int j;
    int begin;
    int stop;
    int fd;
    char *temp;

    if(cub->data->textures[*pos][0] == 'N' && cub->data->textures[*pos][1] == 'O')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] = ' ')
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
    if(cub->data->textures[*pos][0] == 'S' && cub->data->textures[*pos][1] == 'O')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] = ' ')
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
int check_textures_part2(t_cub *cub, int *pos)
{
    int j;
    int begin;
    int stop;
    int fd;
    char *temp;

    if(cub->data->textures[*pos][0] == 'W' && cub->data->textures[*pos][1] == 'E')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] = ' ')
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
    if(cub->data->textures[*pos][0] == 'E' && cub->data->textures[*pos][1] == 'A')
    {
        stop = 0;
        j = 2;
        if(!cub->data->textures[*pos][j])
            return (-1);
        while(cub->data->textures[*pos][j] &&cub->data->textures[*pos][j] = ' ')
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