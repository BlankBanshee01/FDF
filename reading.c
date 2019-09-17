#include "fdf.h"

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

    fd = open(argv, O_RDONLY);
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
    while (*table++)
        printf("\n%s\n", *table);
    return table;
}