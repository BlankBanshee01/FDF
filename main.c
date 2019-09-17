#include "fdf.h"

int main(int argc, char **argv)
{
    t_data data;
    
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, 500, 600, "hello niggors");
    data.img_ptr = mlx_new_image(data.mlx, 500, 600);
    data.image = (int *)mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.size_line, &data.endian);
    if (!check_valid(argv[1]))
    {
        ft_putstr("file not valid");
        return (0);
    }
    reading(argv[1]);

    // int x = 0, y = 5;
    // while (x < 500)
    // {
    //     data.image[y * 600 + x++] = 0x550055;
    // }
    // data.image[3000] = 0xFFFFFF;
    mlx_put_image_to_window(data.mlx, data.window, data.img_ptr, 0, 0);
    mlx_loop (data.mlx);
}