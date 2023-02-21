#include "include/cub.h"
#include "get_next_line/get_next_line.h"

int index_last(char **file)
{
	int	error;
	int	i;

	i = 0;
	error = i;
	i = ft_researchstring(file,"NO",0) + 1;
	if(error == i - 1)
		i = i - 1;
	error = i;
	i = ft_researchstring(file, "SO",i) + 1;
	if(error == i - 1)
		i = i - 1;
		error = i;
		i = ft_researchstring(file,"EA",i) + 1;
	if(error ==i - 1)
		i = i - 1;
		error = i;
		i = ft_researchstring(file,"WE",i) + 1 ;
	if(error == i - 1)
		i = i - 1;
		error = i;
		i = ft_researchstring(file,"F",i) + 1;
	if(error == i - 1)
		i = i - 1;
		error = i;
		i = ft_researchstring(file,"C",i) + 1;
	if(error == i - 1)
		i = i - 1;
	return (i);

}
int fill_map(char **file , t_cub *cub)
{
	int	i;
	int	len_map;
	int	k;
	int	j;
	t_data *x;

	x = (t_data *)malloc(sizeof(t_data));
	k = 0;
	i = index_last(file);
	len_map = 2;
	j = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j] == ' ')
			j++;
		if (file[i][j] != '\n' && file[i][j])
			break;
		i++;
	}
	len_map = ft_maplen(file + i);

	cub->data->x = 2;
	// printf("%p", cub->data->x);
	if(len_map == 0)
		return (-1);
	//cub->data->map = (char **)malloc(sizeof(char *) * (len_map + 1));
	// while(file[i])
	// {
	// 	cub->data->map[k] = ft_strdup(file[i]);
	// 	i++;
	// 	k++;
	// }
	return (1);
}
int is_all_textures_available(char **file)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'S' && file[i][j + 1] == 'O' && (file[i][j + 2] == ' ' || !file[i][j + 2]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'N' && file[i][j + 1] == 'O' && (file[i][j + 2] == ' ' || !file[i][j + 2]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'E' && file[i][j + 1] == 'A' && (file[i][j + 2] == ' ' || !file[i][j + 2]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
		i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'W' && file[i][j + 1] == 'E' && (file[i][j + 2] == ' ' || !file[i][j + 2]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
	if(total < 4)
		return (-1);
	return(1);
}

int is_all_rgb_available(char ** file)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'F' && (file[i][j + 1] == ' ' || !file[i][j + 1]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == 'C' && (file[i][j + 1] == ' ' || !file[i][j + 1]))
			{
				total += 1;
				break;
			}
			j++;
		}
		i++;
	}
	if(total < 2)
		return -1;
	return (1);
}
int is_duplicated(char **file , char *s)
{
	int	i;
	int	j;
	int duplicate;
	char str[2];

	str[0] = s[0];
	if(s[1])
		str[1] = s[1];
	i = 0;
	duplicate = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j])
		{
			if(file[i][j] == str[0])
			{
				if(str[1])
				{
					if(file[i][j + 1] == str[1])
						if(!file[i][j + 2] || file[i][j + 2] == ' ')
							duplicate += 1 ;
				}
				else 
					if(!file[i][j + 1] || file[i][j + 1] == ' ')
						duplicate += 1 ;
			}
			if(duplicate > 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int duplicate_textures(char **file)
{
	if(is_duplicated(file,"SO") == -1)
		return (-1);
	else if(is_duplicated(file,"NO") == -1)
		return (-1);
	else if(is_duplicated(file,"EA") == -1)
		return (-1);
	else if(is_duplicated(file,"WE") == -1)
		return (-1);
	return (1);
}
int duplicate_RGB(char **file)
{
	if(is_duplicated(file,"F") == -1)
		return (-1);
	else if(is_duplicated(file,"C") == -1)
		return (-1);
	return (1);
}
int ft_researchstring(char **files , char *s , int position)
{
	int	i;
	int j;
	int	k;
	
	i = position;
	while(files[i])
	{
		j = 0;
		k = 0;
		while(files[i][j])
		{
			while(s[k] && files[i][j] == s[k])
			{
				k++;
				j++;
				if(!s[k])
					return (i);
			}
			j++;
		}
		i++;
	}
	return (position);
}
int fill_textures(char **files, t_cub *cub)
{
	if (is_all_textures_available(files) == -1)
		return -1;
	if (duplicate_textures(files) == -1)
		return -1;
	int	i;
	int	k;

	cub->data->textures = (char **)malloc(sizeof(char *) * 4);
	if(cub->data->textures == 0)
		return (-1);
	i = 0;
	k = 0;
	if(ft_researchstring(files + i,"SO",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"SO",0)]);
		k += 1;
	}
	if(ft_researchstring(files + i,"NO",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"NO",0)]);
		k += 1;
	}
	if(ft_researchstring(files + i,"EA",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"EA",0)]);
		k += 1;
	}
	if(ft_researchstring(files + i,"WE",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"WE",0)]);
		k += 1;
	}
	if(k == 4)
		return (1);
	return (-1);
}

int fill_RGB(char **files , t_cub *cub)
{
	if(is_all_rgb_available(files) == -1)
		return (-1);
	if(duplicate_RGB(files) == -1)
		return (-1);
	int	i;
	int	k;

	cub->data->RGB = (char **)malloc(sizeof(char *) * 2);
	if(cub->data->textures == 0)
		return (-1);
	i = 0;
	k = 0;
	if(ft_researchstring(files + i,"F",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"F",0)]);
		k += 1;
	}
	if(ft_researchstring(files + i,"C",0) != -1)
	{
		cub->data->textures[k] = ft_strdup(files[ft_researchstring(files + i,"C",0)]);
		k += 1;
	}
	if(k == 2)
		return (1);
	return (-1);
}