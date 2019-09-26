#include "libft.h"

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}