

#include "fdf.h"
// , t_data *data, int color
void    ft_color_pixel(int x, int y, t_data *data)
{
    int color =  0xFFFFFF;
    data->image[y * data->width + x] = color;   
}

void ft_draw(t_data *data)
{
    int i;
    int j;
    int x;
    int y;

    int spacing;

    spacing = 10;
    i = 0;
    y = 0;
    while (i < data->map->y_hight)
    {
        j = 0;
        x = 0;
        while (j < data->map->x_long)
        {
            ft_color_pixel((x + 100), (y + 100), data);
            j++;
            plotLine(, 100, 10, 300, data);
            x = x + spacing;
        }
        y = y + spacing;
        i++;
        

    }

    // plotLine(200, 100, 10, 300, data);

    // int x = 0, y = 100;
    // while (x < data->width)
    // {
    //     ft_color_pixel(x++, y, data, 0xFF);
    // }
}