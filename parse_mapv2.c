#include "../../include/cub.h"


int valid_map(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while(i < cub->data.y)
    {
        j = 0;
        while(j < cub->data.x)
        {
            if(cub->data[i][j] != '1' && i == 0)
                return (-1);
            else if(cub->data[i][j] != '1' && i == cub->data.y - 1)
                return(-1);
            else if(cub->data[i][j] != '1' && i == cub->data.y - 1)
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
int first_last_line(t_data *map)
{
    int i;
    int j;

    j = 0;
    while(map->map[0][j])
    {
        if(map->map[0][j] == '1')
            j++;
        else if(map->map[0][j] == ' ' && j + 1 != ft_strlen(map->map[0]))
            j++;
        return (-1);
    }

    i = ft_maplen(map->map) - 1;
    j = 0;
    while(map->map[i][j])
    {
        if(map->map[i][j] == '1')
            j++;
        else if(map->map[i][j] == ' ' && j + 1 != ft_strlen(map->map[0]))
            j++;
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
        if(map[i][0] == '\n')
            return(0);
        i++;
    }
    return (1);
}
int surrounder_by_1(t_data *map,int x,int y)
{
    int i;
    int bas;
    int haut;

    bas = 0;
    haut = 0;
    if(x == 0)
    {
        i = 0;
        while(map->map[x][i])
        {
            if(map->map[x + 1][i] && map->map[x + 1][i] == '1')
                return (1);
            i++;
        }
    }
    if(x + 1 != ft_maplen(map->map))
    {
        i = 0;
        while(map->map[x][i])
        {
            if(map->map[x + 1][i] && map->map[x + 1][i] == '1')
                bas = 1;
            i++;
        }
        i = 0;
        while(map->map[x][i])
        {
            if(map->map[x - 1][i] && map->map[x - 1][i] == '1')
                haut = 1;
            if(bas && haut)
                return(1);
            i++;
        }
    }
    if( x + 1 != ft_maplen(map->map))
    {
        i = 0;
        while(map->map[x][i])
        {
            if(map->map[x - 1][i] && map->map[x - 1][i] == '1')
                return (1);
            i++;
        }
    }
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

    i = 0;
    if(ft_maplen(cub->data->map) < 3)
        return (-1);
    if(first_last_line(cub->data) == -1)
        return (-1);
    while(cub->data->map[i])
    {
        j = 0;
        while(cub->data->map[i][j])
        {
            s = cub->data->map[i][j];
            if(s != ' ' && s!= '1')
            {
                if(i == 0 || j == 0 || i + 1 == ft_maplen(cub->data->map) || j + 1 == ft_strlen(cub->data->map[i]) || cub->data->map[i][j + 1] == ' ' || cub->data->map[i][j - 1] == ' '
                    || cub->data->map[i + 1][j] == ' ' || cub->data->map[i - 1][j] == ' ')
                {
                    write(1,"invalid map\n",12);
                    return (-1);
                }
            }
            if(s == ' ' && )
            j++;
        }
        i++;
    }
}