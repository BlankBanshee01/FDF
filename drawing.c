

#include "fdf.h"

void    ft_color_pixel(int x, int y, t_data *data, int color)
{
    data->image[y * data->width + x] = color;
}

void ft_draw(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map->y_hight)
    {
        j = 0;
        while (j < data->map->x_long)
        {
            ft_color_pixel((j), (i), data, 0xFF);
            j++;
        }
        i++;
    }
    // int x = 0, y = 100;
    // while (x < data->width)
    // {
    //     ft_color_pixel(x++, y, data, 0xFF);
    // }
}