/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:01:31 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/09/30 21:10:10 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - z;
}

/*
**connect to down point
**connect to right point
*/

static void	ft_draw_iso_3(t_data *data, t_index p, t_vect *vect)
{
	if (p.i < data->map->y_hight - 1)
		plotline(*vect, data);
	vect->y1 = p.y;
	vect->x1 = p.x + data->spc;
	iso(&vect->x1, &vect->y1, vect->z_right);
	if (p.j < data->map->x_long - 1)
		plotline(*vect, data);
}

static void	ft_draw_iso_2(t_data *data, t_index p, t_vect *vect)
{
	vect->z = data->map->map_cord[p.i][p.j];
	if (p.j < data->map->x_long - 1)
		vect->z_right = data->map->map_cord[p.i][p.j + 1];
	if (p.i < data->map->y_hight - 1)
		vect->z_down = data->map->map_cord[p.i + 1][p.j];
	vect->x0 = p.x;
	vect->y0 = p.y;
	vect->y1 = p.y + data->spc;
	vect->x1 = p.x;
	iso(&vect->x0, &vect->y0, vect->z);
	iso(&vect->x1, &vect->y1, vect->z_down);
}

void		ft_draw_iso(t_data *data)
{
	t_index	p;
	t_vect	vect;

	p.i = 0;
	p.y = data->offset_y;
	while (p.i < data->map->y_hight)
	{
		p.j = 0;
		p.x = data->offset_x;
		while (p.j < data->map->x_long)
		{
			ft_draw_iso_2(data, p, &vect);
			ft_draw_iso_3(data, p, &vect);
			p.j++;
			p.x = p.x + data->spc;
		}
		p.y = p.y + data->spc;
		p.i++;
	}
}
