#include <mlx.h>
#include <stdio.h>
#include "libft/libft.h"

typedef	struct	s_data
{
		void	*mlx;
		void	*window;
		void	*img_ptr;
		int		*image; //buff
		int 	bits_per_pixel;
		int 	size_line;
		int 	endian;
}				t_data;

typedef struct	s_map
{
		int		x_long;
		int		y_hight;
		int		**map_cord;

}				t_map;

int		check_valid(char *argv);
char	**reading(char *argv);
void	storing_length(char **table, t_map **map);
int		reading_manager(char *argv);





// pixel representation in memory

//     A        R        G      B        
// 00000000 00000000 00000000 00000000

// color = 0xFF00FF