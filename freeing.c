#include "fdf.h"

void    free_int(int ***to_free, int length)
{
    int     i;

    i = 0;
    while (i < length)
    {
        ft_memdel((void **)&(*to_free)[i]);
        i++;
    }
}

void    free_table(char ***to_free)
{
    int i;

    i = 0;
    while ((*to_free)[i])
    {
        ft_strdel(&(*to_free)[i]);
        i++;
    }
}

void quitting_esc(t_data *data)
{
    free_int(&data->map->map_cord, data->map->y_hight);
    exit(0);
}
