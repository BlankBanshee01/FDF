/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:43:17 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/09/30 20:58:29 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	flip_coord(t_vect *vect)
{
	int tmp;

	tmp = vect->x0;
	vect->x0 = vect->x1;
	vect->x1 = tmp;
	tmp = vect->y0;
	vect->y0 = vect->y1;
	vect->y1 = tmp;
}

static void	setting_var(t_plo *plo, t_vect vect)
{
	plo->dx = vect.x1 - vect.x0;
	plo->dy = vect.y1 - vect.y0;
	plo->xi = 1;
	plo->yi = 1;
	plo->y = vect.y0;
	plo->x = vect.x0;
}

static void	plotlinehigh(int rev, t_vect vect, t_data *data)
{
	t_plo plo;

	rev ? flip_coord(&vect) : rev;
	setting_var(&plo, vect);
	if (plo.dx < 0)
	{
		plo.xi = -1;
		plo.dx = -plo.dx;
	}
	plo.d = 2 * plo.dx - plo.dy;
	while (plo.y <= vect.y1)
	{
		ft_color_pixel(plo.x, plo.y, data);
		if (plo.d > 0)
		{
			plo.x = plo.x + plo.xi;
			plo.d = plo.d - 2 * plo.dy;
		}
		plo.d = plo.d + 2 * plo.dx;
		plo.y++;
	}
}

static void	plotlinelow(int rev, t_vect vect, t_data *data)
{
	t_plo plo;

	rev ? flip_coord(&vect) : rev;
	setting_var(&plo, vect);
	if (plo.dy < 0)
	{
		plo.yi = -1;
		plo.dy = -plo.dy;
	}
	plo.d = 2 * plo.dy - plo.dx;
	while (plo.x < vect.x1)
	{
		ft_color_pixel(plo.x, plo.y, data);
		if (plo.d > 0)
		{
			plo.y = plo.y + plo.yi;
			plo.d = plo.d - 2 * plo.dx;
		}
		plo.d = plo.d + 2 * plo.dy;
		plo.x++;
	}
}

void		plotline(t_vect vect, t_data *data)
{
	if (abs(vect.y1 - vect.y0) < abs(vect.x1 - vect.x0))
	{
		if (vect.x0 > vect.x1)
			plotlinelow(1, vect, data);
		else
			plotlinelow(0, vect, data);
	}
	else
	{
		if (vect.y0 > vect.y1)
			plotlinehigh(1, vect, data);
		else
			plotlinehigh(0, vect, data);
	}
}
