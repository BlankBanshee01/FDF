#include "fdf.h"

void    ft_color_pixel(int x, int y, t_data *data)
{
    int color = 0xFFFFFF;
	if (x >= data->width || x < 0 || y >= data->height || y < 0)
		return ;
    data->image[y * data->width + x] = color;   
}

void ft_draw(t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    t_index p;


    int spacing;

    spacing = 27;
    p.i = 0;
    p.y = 0;
    while (p.i < data->map->y_hight)
    {
        p.j = 0;
        p.x = 0;
        while (p.j < data->map->x_long)
        {
            if(p.i < data->map->y_hight - 1)
                plotLine(p.x, p.y, p.x, p.y + spacing, data);
            if(p.j < data->map->x_long - 1)
                plotLine(p.x, p.y, p.x + spacing, p.y, data);
            p.j++;
            p.x = p.x + spacing;
        }
        p.y = p.y + spacing;
        p.i++;
    }
}