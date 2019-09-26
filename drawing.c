

#include "fdf.h"


static void iso(int *x, int *y, int z)
{
    int tmp;

    tmp = *x;
     printf("----------\n\nb1 %d %d %d\n", *x, *y, z);
    *x = (tmp - *y) * cos(0.523599);
    printf("b2 %d %d %d\n", *x, *y, z);
    *y = (tmp + *y) * sin(0.523599) -z ;
    printf("after %d %d %d\n", *x, *y, z);
}

// , t_data *data, int color
void    ft_color_pixel(int x, int y, t_data *data)
{
    int color = 0xFFFFFF;
	if (x >= data->width || x < 0 || y >= data->height || y < 0)
		return ;
    data->image[y * data->width + x] = color;   
}

void    ft_draw_iso_2(t_data *data, t_index p)
{

}

void ft_draw_iso(t_data *data)
{
    t_index p;
    t_vect  vect;

    data->spc = 5;
    p.i = 0;
    p.y = 0;
    // plotLine(1, vect.y0, vect.x1, vect.y1, data);
    while (p.i < data->map.y_hight)
    {
        p.j = 0;
        p.x = 400;
        while (p.j < data->map.x_long)
        {
            vect.z = data->map.map_cord[p.i][p.j];
            if (p.j < data->map.x_long - 1)
                vect.z_right = data->map.map_cord[p.i][p.j + 1];

            vect.x0 = p.x;
            vect.y0 = p.y;
            vect.y1 = p.y + data->spc;
            vect.x1 = p.x;
            iso(&vect.x0, &vect.y0, vect.z);
  if (p.i < data->map.y_hight - 1)
                vect.z_down = data->map.map_cord[p.i + 1][p.j];
            printf("before %d %d\n",vect.x1,vect.y1);
            iso(&vect.x1, &vect.y1, vect.z_down);
            printf("after %d %d\n",vect.x1,vect.y1);
// exit(1);
            if(p.i < data->map.y_hight - 1)
                plotLine(vect.x0, vect.y0, vect.x1, vect.y1, data);  // connect to down point
          
            vect.y1 = p.y;
            vect.x1 = p.x + data->spc;
            iso(&vect.x1, &vect.y1, vect.z_right);
            if(p.j < data->map.x_long - 1)
                plotLine(vect.x0, vect.y0, vect.x1, vect.y1, data); // connect to right point           
            p.j++;
            p.x = p.x + data->spc;
        }
        p.y = p.y + data->spc;
        p.i++;
    }
}

void ft_draw(t_data *data)
{
    int i;
    int j;
    int x;
    int y;

    int spacing;

    spacing = 27;
    i = 0;
    y = 0;
    while (i < data->map.y_hight)
    {
        j = 0;
        x = 0;
        while (j < data->map.x_long)
        {
            if(i < data->map.y_hight - 1)
                plotLine(x, y, x, y + spacing, data);
            if(j < data->map.x_long - 1)
                plotLine(x, y, x + spacing, y, data);
            j++;
            x = x + spacing;
        }
        y = y + spacing;
        i++;
    }
}


// void ft_draw_iso(t_data *data)
// {
//        int i;
//     int j;
//     int x;
//     int y;
//     int z;
//     t_vect vect;

// /*
// vect1 rotated point
// vect2 rotated next point
// */
//     data->spc = 10;
//     i = 0;
//     y = 300;
//     int x1;
//     int y1;
//     int tmp_x;
    
//     while (i < data->map.y_hight)
//     {
//         j = 0;
//         x = 200;
//         while (j < data->map.x_long)
//         {
//             z = data->map.map_cord[i][j];
//             int z_right;
//             int z_down;
            
//             if (j < data->map.x_long - 1)
//                 z_right = data->map.map_cord[i][j + 1];
//             if (j < data->map.y_hight - 1)
//                 z_down = data->map.map_cord[i + 1][j];
//             vect.x = x;
//             vect.y = y - z;
//             int down_next_y = y + data->spc - z_down;
//             int down_next_x = x;
//             int right_next_y = y - z_right;
//             int right_next_x =  x + data->spc;
//             // vect.y1 = y + data->spc - z1;
//             vect.x1 = x + data->spc;
//             // iso(&vect.x, &vect.y, z);
//             // iso(&vect.x1, &vect.y1, z1);
//             // printf("x=%d\ty=%d\tx1=%d\ty1=%d         z %d | z1 %d\n", vect.x, vect.y, vect.x1, vect.y1, z , z1);
//             // if(i < data->map.y_hight - 1)
//                 plotLine(x, y - z, down_next_x, down_next_y, data);  // connect to down point
//             // ft_color_pixel(vect.x, vect.y, data);
//             // ft_color_pixel(vect.x1, vect.y, data);
//             // if(j < data->map.x_long - 1)
//                 plotLine(x, y - z, right_next_x, right_next_y, data); // connect to right point
//             j++;
//             x = x + data->spc;
//         }
//         y = y + data->spc;
//         i++;
//     }
// }




// VERSION 2



// void ft_draw_iso(t_data *data)
// {
//     int i;
//     int j;
//     int x;
//     int y;
//     int z;
//     t_vect vectvec;

// /*
// vectvec1 rotated point
// vectvec2 rotated next point
// */
//     data->spc = 15;
//     i = 0;
//     y = 0;
//     int x1;
//     int y1;
//     int tmp_x;
    
//     while (i < data->map.y_hight)
//     {
//         j = 0;
//         x = 400;
//         while (j < data->map.x_long)
//         {
//             z = data->map.map_cord[i][j];
//             int z_right;
//             int z_down;
//             printf("%d %d\n", i, j);
//             if (j < data->map.x_long - 1)
//                 z_right = data->map.map_cord[i][j + 1];
//             if (j < data->map.y_hight - 1)
//                 z_down = data->map.map_cord[i + 1][j];
//             vectvec.x0 = x;
//             vectvec.y0 = y;
//             int down_next_y = y + data->spc /* - z_down*/;
//             int down_next_x = x;
//             int right_next_y = y /*- z_right*/;
//             int right_next_x =  x + data->spc;
//             iso(&vectvec.x0, &vectvec.y0, z);
//             iso(&down_next_x, &down_next_y, z_down);
//             iso(&right_next_x, &right_next_y, z_right);
//             // printf("x=%d\ty=%d\tx1=%d\ty1=%d         z %d | z1 %d\n", vectvec.x, vectvec.y, vectvec.x1, vectvec.y1, z , z1);
//             if(i < data->map.y_hight - 1)
//                 plotLine(vectvec.x0, vectvec.y0, down_next_x, down_next_y, data);  // connect to down point
//             // ft_color_pixel(vectvec.x, vectvec.y, data);
//             // ft_color_pixel(vectvec.x1, vectvec.y, data);
//             if(j < data->map.x_long - 1)
//                 plotLine(vectvec.x0, vectvec.y0, right_next_x, right_next_y, data); // connect to right point
//             j++;
//             x = x + data->spc;
//         }
//         y = y + data->spc;
//         i++;
//     }
// }

