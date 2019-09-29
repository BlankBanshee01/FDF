#include "fdf.h"

void parallel_proj(t_data *data)
{
    mlx_clear_window(data->mlx , data->window);
    mlx_destroy_image(data->mlx, data->img_ptr);
    data->img_ptr = mlx_new_image(data->mlx, data->width, data->height);
    data->image = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->size_line, &data->endian);
    ft_draw(data);
    mlx_put_image_to_window(data->mlx, data->window, data->img_ptr, 0, 0);
    mlx_string_put(data->mlx, data->window, 20, 20, 0xFFFFFF, data->map_name);
    data->projection = 'p';
}

void iso_proj(t_data *data)
{
    mlx_clear_window(data->mlx , data->window);
    mlx_destroy_image(data->mlx, data->img_ptr);
    data->img_ptr = mlx_new_image(data->mlx, data->width, data->height);
    data->image = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->size_line, &data->endian);
    ft_draw_iso(data);
    mlx_put_image_to_window(data->mlx, data->window, data->img_ptr, 0, 0);
    mlx_string_put(data->mlx, data->window, 20, 20, 0xFFFFFF, data->map_name);
    data->projection = 'i';
}

void    spacing(t_data *data, int keycode)
{
    if (keycode == 69)
        data->spc += 5;
    else
        data->spc > 5 ? data->spc -= 5 : data->spc == 0;
    mlx_clear_window(data->mlx , data->window);
    mlx_destroy_image(data->mlx, data->img_ptr);
    data->img_ptr = mlx_new_image(data->mlx, data->width, data->height);
    data->image = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (data->projection == 'p')
        ft_draw(data);
    else
        ft_draw_iso(data);
    mlx_put_image_to_window(data->mlx, data->window, data->img_ptr, 0, 0);
    mlx_string_put(data->mlx, data->window, 20, 20, 0xFFFFFF, data->map_name);
}

void    moving(t_data *data, int keycode)
{
    if (keycode == 123)
        data->offset_x -= 50;
    if (keycode == 126)
        data->offset_y -= 50;
    if (keycode == 124)
        data->offset_x += 50;
    if (keycode == 125)
        data->offset_y += 50;
    mlx_clear_window(data->mlx , data->window);
    mlx_destroy_image(data->mlx, data->img_ptr);
    data->img_ptr = mlx_new_image(data->mlx, data->width, data->height);
    data->image = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->size_line, &data->endian);
    if (data->projection == 'p')
        ft_draw(data);
    else
        ft_draw_iso(data);
    mlx_put_image_to_window(data->mlx, data->window, data->img_ptr, 0, 0);
    mlx_string_put(data->mlx, data->window, 20, 20, 0xFFFFFF, data->map_name);
}

int key_press(int keycode, t_data *data)
{   
    printf("%d\n",keycode);
    if (keycode == 35)
        parallel_proj(data);
    if (keycode == 34)
        iso_proj(data);
    if (keycode == 53)
        quitting_esc(data);
    if (keycode == 69 || keycode == 78)
        spacing(data, keycode);
    if (keycode == 123 || keycode == 126 || keycode == 124 || keycode == 125)
        moving(data, keycode);
    // esc 53  p 35 i 34 +69 -78 <-123 |126 ->124 ,|,125
    return 1;
}
