#include "include/cub.h"

int check_arguments_available(int argc,char **argv)
{
    char *output;
    int  error;

    output = NULL;

    if (argc !=2)
    {
        output = "Error : The number of arguments is 2\n";
        write(2,output,ft_strlen(output));
        return (-1);
    }
    else
    {
        error = ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,".cub",4);
        if(error != 0)
        {
            output = "Error : Wrong File\n";
            write(2,output,ft_strlen(output));
            return (-1);
        }      
    }
    return (1);
}