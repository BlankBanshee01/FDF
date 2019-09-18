#include "fdf.h"

void    free_int(int ***to_free, int length)
{
    int     i;

    i = 0;
    while (i < length)
    {
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

int     line_length(char *str)
{
	size_t	i;
	size_t	a;
    char    c;

	i = 0;
	a = 0;
    c = ' ';
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

int    check_valid(char *argv)
{
    int fd;
    char *line;
    int length;

    if ((fd = open(argv, O_RDONLY)) <= 0)
        return (0);
    if (get_next_line(fd, &line))
        length = line_length(line);
    while (get_next_line(fd, &line))
    {
        if (length > line_length(line))
            return (0);
    }
    close(fd);
    return (1);
}

char **reading(char *argv)
{
    int fd;
    int i;
    int j;
    int len;
    char *line;
    char *joined;
    char *tmp;
    char **table;

    fd = open(argv, O_RDONLY); 
    joined = ft_strnew(1);
    tmp = ft_strnew(1);
    while (get_next_line(fd, &line) > 0)
    {
        tmp = ft_strjoin(joined, line);
        free(joined);
        joined = ft_strjoin(tmp, "\n");
        free(line);
        free(tmp);
    }
    table = ft_strsplit(joined, '\n');
    return table;
}

void    storing_length(char **table, t_map **map)
{
    (*map)->x_long = line_length(table[0]);
    (*map)->y_hight = 0;
    while (*table++)
        (*map)->y_hight++;
}

void   storing_data(t_map **map, char **table)
{
    int     i;
    char    **tab;
    int j;

    i = 0;
    printf("x = %d  y = %d", (*map)->x_long, (*map)->y_hight);
    (*map)->map_cord[2][1] = 15;
    printf("\nhere\n");
    while (table[i])
    {
        tab = ft_strsplit(table[i], ' ');
        j = 0;
        while (tab[j])
        {
            (*map)->map_cord[i][j] = ft_atoi(tab[j]);
            j++;
        }
        i++;
        free_table(&tab);
    }
}

t_map    *reading_manager(char *argv)
{
    int     i;
    int     j;
    t_map   *map;
    char    **table;

    i = 0;
    j = 0;
    if (!check_valid(argv))
    {
        ft_putstr("file not valid");
        return (0);
    }
    if (!(map = (t_map *)malloc(sizeof(t_map))))
        return (0);
    table = reading(argv);
    storing_length(table, &map);
    map->map_cord = malloc(sizeof(int *) * map->y_hight);
    while (i <= map->y_hight)
    {
        map->map_cord[i] = (int *)malloc(sizeof(int) * map->x_long);
        i++;
    }
    storing_data(&map, table);
    for (int h = 0; h < map->y_hight; h++)
    {
        for (int k = 0; k < map->x_long; k++)
        {
            printf("%d ", map->map_cord[h][k]);
        }
        printf("\n");
    }
    free_table(&table);
    
    return (map);
}