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
		int		x;
		int		y;
		int		z;
}				t_map;

int    check_valid(char *argv);
char **reading(char *argv);




// pixel representation in memory

//     A        R        G      B        
// 00000000 00000000 00000000 00000000

// color = 0xFF00FF