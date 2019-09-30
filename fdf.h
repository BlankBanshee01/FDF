#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

typedef struct	s_map
{
		int		x_long;
		int		y_hight;
		int		**map_cord;

}				t_map;

typedef struct	s_vect
{
		int		x0;
		int		y0;
		int		x1;
		int		y1;
		int		z;
		int		z_down;
		int		z_right;
}				t_vect;


typedef struct	s_index
{
		int		x;
		int		y;
		int		i;
		int		j;
}				t_index;

typedef struct	s_ploting
{
	int dx;
	int dy;
	int D;
	int x;
	int xi;
	int yi;
	int y;
}				t_plo;

typedef	struct	s_data
{
		void	*mlx;
		void	*window;
		void	*img_ptr;
		int		height;
		int 	width;
		int		*image;
		int 	bits_per_pixel;
		int 	size_line;
		int 	endian;
		int		spc;
		char	*map_name;
		char	projection;
		int		offset_y;
		int		offset_x;
		int		color;
		t_map	*map;
}				t_data;


t_map	*reading_manager(char *argv);
void	ft_draw(t_data *data);
void	ft_color_pixel(int x, int y, t_data *data);
void	ft_draw_iso(t_data *data);
void	plotLine(t_vect vect, t_data *data);
void	free_int(int ***to_free, int length);
void	free_table(char ***to_free);
void	quitting_esc(t_data *data);
void	printing_usage(t_data *data);
void	reinitialize_win(t_data *data);
int		key_press(int keycode, t_data *data);

/*
	pixel representation in memory

       A        R        G      B        
   00000000 00000000 00000000 00000000

   color = 0xFF00FF
*/
