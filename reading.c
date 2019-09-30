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

static int  map_length_valid(char *argv, t_map **map)
{
    int     fd;
    char    *line;
    int     len;
    int ret;

    len = -1;
    (*map)->y_hight = 0;
    fd = open(argv, O_RDONLY);
    ret = get_next_line(fd, &line);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (len == -1)
                len = ft_wcount2(line, ' ');
        if ((int)ft_wcount2(line, ' ') != len || len == 0)
        {
            ft_strdel(&line);
            return (0);
        }
        free(line);
        (*map)->y_hight+=1;
    }
    if (ret == -1)
        {
            ft_putstr("This is a directory need a file.fdf\n");
            exit(0);
        }
    (*map)->x_long = len;
    close(fd);
    return (1);
}

static void reading(char *argv, t_map **map)
{
    int fd;
    int i;
    int j;
    char *line;
    char **table;
    i = 0;

    fd = open(argv, O_RDONLY); 
    while (get_next_line(fd, &line) > 0)
    {
        table = ft_strsplit(line, ' ');
        j = 0;
        while (table[j])
        {    
           (*map)->map_cord[i][j] = ft_atoi(table[j]);
            j++;
        }
        free(line);
        free_table(&table);
        i++;
    }
}

t_map    *reading_manager(char *argv)
{
    int     i;
    int     j;
    t_map   *map;

    j = 0;
    i = 0;
    if (open(argv, O_RDONLY) == -1)
    {
        perror("error");
        exit(0);
    }
    map = (t_map *)malloc(sizeof(t_map));
    if (!map_length_valid(argv, &map))
    {
        ft_putstr("file not valid");
        free(map);
        exit(0);
    }
    map->map_cord = malloc(sizeof(int *) * map->y_hight + 1);
    while (i <= map->y_hight)
        map->map_cord[i++] = (int *)malloc(sizeof(int) * map->x_long);
    reading(argv, &map);

    return (map);
}
    // free_int(&map->map_cord, map->y_hight);
    // free(map->map_cord);
    // free(map);