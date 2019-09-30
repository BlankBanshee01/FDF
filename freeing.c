/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:10:31 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/09/30 21:11:44 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isdir(int ret, int fd, t_map **map)
{
	if (ret == -1)
	{
		close(fd);
		free(*map);
		ft_putstr("Argument is a directory.\nUsage: ./fdf file.fdf\n");
		exit(0);
	}
}

void	free_int(int ***to_free, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		ft_memdel((void **)&(*to_free)[i]);
		i++;
	}
}

void	free_table(char ***to_free)
{
	int i;

	i = 0;
	while ((*to_free)[i])
	{
		ft_strdel(&(*to_free)[i]);
		i++;
	}
}

void	quitting_esc(t_data *data)
{
	free_int(&data->map->map_cord, data->map->y_hight);
	exit(0);
}
