/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:40:49 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/09/30 21:18:58 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_color_pixel(int x, int y, t_data *data)
{
	if (x >= data->width || x < 0 || y >= data->height || y < 0)
		return ;
	data->image[y * data->width + x] = data->color;
}

static void		ft_draw2(t_vect *vect, t_index *p, t_data *data)
{
	vect->x0 = p->x;
	vect->y0 = p->y;
	if (p->i < data->map->y_hight - 1)
	{
		vect->x1 = p->x;
		vect->y1 = p->y + data->spc;
		plotline(*vect, data);
	}
	if (p->j < data->map->x_long - 1)
	{
		vect->x1 = p->x + data->spc;
		vect->y1 = p->y;
		plotline(*vect, data);
	}
	p->j++;
	p->x = p->x + data->spc;
}

void			ft_draw(t_data *data)
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
			ft_draw2(&vect, &p, data);
		p.y = p.y + data->spc;
		p.i++;
	}
}
