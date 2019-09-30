#include "fdf.h"

static  void    redo_proj(t_data *data, int keycode)
{
    if (keycode == 35)
        {
            data->projection = 'p';
            ft_draw(data);
        }
    else
        {
            data->projection = 'i';
            ft_draw_iso(data);
        }
    reinitialize_win(data);
}

static void    spacing(t_data *data, int keycode)
{
    keycode == 69 ? data->spc += 5 : data->spc > 5 ? data->spc -= 5 : data->spc == 0;
    reinitialize_win(data);
}

static void    moving(t_data *data, int keycode)
{
    keycode == 123 ? data->offset_x -= 50 : data->offset_x;
    keycode == 126 ? data->offset_y -= 50 : data->offset_y;
    keycode == 124 ? data->offset_x += 50 : data->offset_x;
    keycode == 125 ? data->offset_y += 50 : data->offset_y;
    reinitialize_win(data);
}

void   change_color(t_data *data)
{
    if (data->color == 0xFFFFFF)
        data->color = 0xFF0000;
    else if (data->color == 0xFF0000)
        data->color = 0x00FF00;
    else if (data->color == 0x00FF00)
        data->color = 0x0000FF;
    else if (data->color == 0x0000FF)
        data->color = 0xFFFFFF;
    reinitialize_win(data);
}
    
/* esc 53  p 35 i 34 +69 -78 <-123 |126 ->124 ,|,125 */

int key_press(int keycode, t_data *data)
{   
    keycode == 35 || keycode == 34 ? redo_proj(data, keycode) : keycode;
    keycode == 53 ? quitting_esc(data) : keycode;
    keycode == 69 || keycode == 78 ? spacing(data, keycode) : keycode;
    keycode == 8 ? change_color(data) : keycode;
    if (keycode == 123 || keycode == 126 || keycode == 124 || keycode == 125)
        moving(data, keycode);
    return 1;
}
