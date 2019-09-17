
#include "libft.h"

static int	putline(const int fd, char **line, char **stat)
{
	int i;

	i = 0;
	while (stat[fd][i] != '\0' && stat[fd][i] != '\n')
		i++;
	if (stat[fd][i] == '\n')
	{
		*line = ft_strsub(stat[fd], 0, i);
		stat[fd] = ft_strdup(stat[fd] + i + 1);
		if (stat[fd][0] == '\0')
			ft_strdel(&stat[fd]);
	}
	else if (stat[fd][i] == '\0')
	{
		*line = ft_strdup(stat[fd]);
		ft_strdel(&stat[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			re;
	char		buffer[BUFF_SIZE + 1];
	static char	*stat[4096];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 4096)
		return (-1);
	while ((re = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (stat[fd] == NULL)
			stat[fd] = ft_strnew(1);
		buffer[re] = '\0';
		stat[fd] = ft_strjoin(stat[fd], buffer);
	}
	if (re < 0)
		return (-1);
	if (re == 0 && (stat[fd] == NULL || stat[fd][0] == '\0'))
		return (0);
	return (putline(fd, line, stat));
}
