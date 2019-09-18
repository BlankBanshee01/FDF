#include "fdf.h"

int main(int argc, char **argv)
{
    t_data data;
    
    data.mlx = mlx_init();
    data.width = 500;
    data.height = 500;
    data.window = mlx_new_window(data.mlx, data.width, data.height, "hello niggors");
    data.img_ptr = mlx_new_image(data.mlx, data.width, data.height);
    data.image = (int *)mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.size_line, &data.endian);
    data.map = reading_manager(argv[1]);
    ft_draw(&data);
    mlx_put_image_to_window(data.mlx, data.window, data.img_ptr, 0, 0);
    mlx_loop (data.mlx);
}

