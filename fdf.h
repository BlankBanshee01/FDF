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

typedef	struct	s_data
{
		void	*mlx;
		void	*window;
		void	*img_ptr;
		int		height;
		int 	width;
		int		*image; //buff
		int 	bits_per_pixel;
		int 	size_line;
		int 	endian;
		t_map	*map;
}				t_data;


int		check_valid(char *argv);
char	**reading(char *argv);
void	storing_length(char **table, t_map **map);
t_map		*reading_manager(char *argv);
void ft_draw(t_data *data);
void    ft_color_pixel(int x, int y, t_data *data);
void    plotLineHigh(int x0,int y0,int x1,int y1, t_data *data);



// pixel representation in memory

//     A        R        G      B        
// 00000000 00000000 00000000 00000000

// color = 0xFF00FF