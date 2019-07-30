#include </Users/banshee/Desktop/FDF/MinilibX/elcapitan/mlx.h>
#include <stdio.h>
#include "./GetNextLineV2/get_next_line.h"

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
// pixel representation in memory

//     A        R        G      B        
// 00000000 00000000 00000000 00000000

// color = 0xFF00FF