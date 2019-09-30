#include "fdf.h"

void    printing_usage(t_data *data)
{
    mlx_string_put(data->mlx, data->window, 20, 10, 0xFFFFFF, data->map_name);
    mlx_string_put(data->mlx, data->window, 1600, 930, 0xFFFFFF, "P   : Parallel Projection");
    mlx_string_put(data->mlx, data->window, 1600, 960, 0xFFFFFF, "I   : True Isometric Projection");
    mlx_string_put(data->mlx, data->window, 1600, 990, 0xFFFFFF, "+ - : To Zoom In and Out");
    mlx_string_put(data->mlx, data->window, 1600, 1020, 0xFFFFFF, "C   : Change Color W->R->G->B");
    mlx_string_put(data->mlx, data->window, 1600, 1050, 0xFFFFFF, "ESC : To Quit");
}
void    initilazing_data(t_data *data, char *argv)
{
    data->mlx = mlx_init();
    data->width = 1920;
    data->height = 1080;
    data->map = reading_manager(argv);
    data->window = mlx_new_window(data->mlx, data->width, data->height, "FDF");
    data->img_ptr = mlx_new_image(data->mlx, data->width, data->height);
    data->image = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->size_line, &data->endian);
    data->map_name = argv;
    data->spc = 10;
    data->projection = 'i';
    data->offset_x = 100;
    data->offset_y = 100;
    data->color = 0xFFFFFF;
}

int main(int argc, char **argv)
{
    t_data data;
    
    initilazing_data(&data, argv[1]);
    ft_draw_iso(&data);
    mlx_put_image_to_window(data.mlx, data.window, data.img_ptr, 0, 0);
    mlx_key_hook(data.window, key_press, &data);
    printing_usage(&data);
    mlx_loop (data.mlx);
}

