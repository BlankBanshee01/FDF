#include "get_next_line.h"
#include <stdio.h>

char **reading(int argc, char **argv)
{
    int fd;
    int i;
    int j;
    int len;
    char *line;
    char *joined;
    char *tmp;
    char **table;

    fd = open(argv[1], O_RDONLY); 
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
    while (*table++)
        printf("\n%s\n", *table);
    return table;
}