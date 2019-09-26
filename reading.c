#include "fdf.h"


static unsigned int	ft_wcount2(const char *str, char c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (str[i] != c && str[i])
		a++;
	while (str[i])
	{
		if (str[i + 1] != c && str[i + 1] && str[i] == c)
			a++;
		i++;
	}
	return (a);
}


void    free_int(int ***to_free, int length)
{
    int     i;

    i = 0;
    while (i < length)
    {printf("H ");
        ft_memdel((void **)&(*to_free)[i]);
        i++;
    }
}

void    free_table(char ***to_free)
{
    int i;

    i = 0;
    while ((*to_free)[i])
    {
        ft_strdel(&(*to_free)[i]);
        i++;
    }
}

static int  map_length_valid(char *argv, t_map *map)
{
    int     i;
    int     fd;
    char    *line;
    int     len;
    char    **table;

    i = 0;
    len = -1;
    fd = open(argv, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        if (len == -1)
                len = ft_wcount2(line, ' ');
        if (ft_wcount2(line, ' ') != len || len == 0)
        {
            ft_strdel(&line);
            return (0);
        }
        free(line);
        i++;
    }
    map->x_long = len;
    map->y_hight = i;
    close(fd);
    return (1);
}

// int    check_valid(char *argv)
// {
//     int fd;
//     char *line;
//     int length;

//     if ((fd = open(argv, O_RDONLY)) <= 0)
//         return (0);
//     if (get_next_line(fd, &line))
//         length = line_length(line);
//     while (get_next_line(fd, &line))
//     {
//         if (length > line_length(line))
//             return (0);
//     }
//     close(fd);
//     return (1);
// }

static void reading(char *argv, t_map *map)
{
    int fd;
    int i;
    int j;
    int len;
    char *line;
    char *joined;
    char *tmp;
    char **table;
    len = -1;
    i = 0;

    fd = open(argv, O_RDONLY); 
    while (get_next_line(fd, &line) > 0)
    {
        table = ft_strsplit(line, ' ');
        j = 0;
        while (table[j])
        {    
           map->map_cord[i][j] = ft_atoi(table[j]);
            j++;
        }
        free(line);
        free_table(&table);
        i++;
    }
}

t_map    reading_manager(char *argv)
{
    int     i;
    int     j;
    t_map   map;

    j = 0;
    i = 0;

    if (!map_length_valid(argv, &map))
    {
        ft_putstr("file not valid");
        exit(0);
    }
    map.map_cord = malloc(sizeof(int *) * map.y_hight + 1);
    while (i <= map.y_hight)
    {
        map.map_cord[i] = (int *)malloc(sizeof(int) * map.x_long);
        i++;
    }
    reading(argv, &map);
    // free_int(&map.map_cord, map.y_hight);
    // free(map.map_cord);
    // free(map);
    return (map);
}