#include "../../include/cub.h"

int ft_ctoi(char c)
{
	int b = (int)c - 48;
    return (b);
}
int check_rgb(t_cub *cub , int i)
{
    int j;
    int len;
    int len_virgule;
    char *temp;
    if(cub->data->RGB[i][0] == 'F' || cub->data->RGB[i][0] == 'C')
    {
        j = 0;
        while(cub->data->RGB[i][j] && cub->data->RGB[i][j] == ' ')
            j++;
        len_virgule = 0;
        while(cub->data->RGB[i][j])
        {
            len = 0;
            while(cub->data->RGB[i][j] && cub->data->RGB[i][j] != ',')
            {
                if(!ft_isdigit(cub->data->RGB[i][j]))
                    return (-1);
                len++;
                if(len == 3)
                    return (-1);
                if(ctoi(cub->data->RGB[i][j]) <= 2 && ctoi(cub->data->RGB[i][j]) >= 0 && len == 0)
                {
                    if (!len == 2 && ft_isdigit(cub->data->RGB[i][j + 1]))
                        continue;
                    temp = ft_substr(cub->data->RGB[i], j - 2, len);
                    //some rgb code
                    free(temp);
                }
                else if(len == 0 && ctoi(cub->data->RGB[i][j]) > 2 && ctoi(cub->data->RGB[i][j]) < 0)
                    return(-1);
                else if(len != 0 && ctoi(cub->data->RGB[i][j]) > 5 && ctoi(cub->data->RGB[i][j]) < 0)
                    return -1;
                else if(len != 0 && ctoi(cub->data->RGB[i][j]) <= 5 && ctoi(cub->data->RGB[i][j]) >= 0)
                {
                    // some code rgb
                }
                len_virgule++;
                j++;       
            }
            if(len_virgule == 2)
                break;
        }
        len = 0;
        while(cub->data->RGB[i][j])
        {
            
            if(!ft_isdigit(cub->data->RGB[i][j]))
                return (-1);
            if(ctoi(cub->data->RGB[i][j]) <= 5 && ctoi(cub->data->RGB[i][j]) >= 0)
            {
                if (!len == 2 && ft_isdigit(cub->data->RGB[i][j + 1]))
                    continue;
                temp = ft_substr(cub->data->RGB[i], j - 2, 3);
                //some rgb code
                free(temp);
            }
            else
                return (-1);
        }
    }
}
int parse_rgb(t_cub *cub)
{
    int i;

    i = 0;
    while(cub->data->RGB[i])
    {
		if(check_rgb(cub,i) == -1)
			return (-1);
		i++;
    }
	return (1);
}