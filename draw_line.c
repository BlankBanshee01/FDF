#include "fdf.h"

static void flip_coord(t_vect *vect)
{
	int tmp;

	tmp = vect->x0;
	vect->x0 = vect->x1;
	vect->x1 = tmp;
	tmp = vect->y0;
	vect->y0 = vect->y1;
	vect->y1 = tmp;	
}

static void setting_var(t_plo *plo, t_vect vect)
{
	plo->dx = vect.x1 - vect.x0;
	plo->dy = vect.y1 - vect.y0;
	plo->xi = 1;
	plo->yi = 1;
	plo->y = vect.y0;
	plo->x = vect.x0;
}

static void    plotLineHigh(int rev, t_vect vect, t_data *data)
{
	t_plo plo;

	rev ? flip_coord(&vect) : rev;
	setting_var(&plo, vect);
	if (plo.dx < 0)
	{
		plo.xi = -1;
		plo.dx = -plo.dx;
	}
	plo.D = 2*plo.dx - plo.dy;
	while (plo.y <= vect.y1)
	{
		ft_color_pixel(plo.x,plo.y, data);
		if (plo.D > 0)
		{
			plo.x = plo.x + plo.xi;
			plo.D = plo.D - 2*plo.dy;
		}
		plo.D = plo.D + 2*plo.dx;
        plo.y++;
	}
}

static void    plotLineLow(int rev, t_vect vect, t_data *data)
{
	t_plo plo;

	rev ? flip_coord(&vect) : rev;
	setting_var(&plo, vect);
	if (plo.dy < 0)
	{
		plo.yi = -1;
		plo.dy = -plo.dy;
	}
	plo.D = 2*plo.dy - plo.dx;
	while (plo.x < vect.x1)
	{
		ft_color_pixel(plo.x,plo.y, data);
		if (plo.D > 0)
		{
			plo.y = plo.y + plo.yi;
			plo.D = plo.D - 2*plo.dx;
		}
		plo.D = plo.D + 2*plo.dy;
        plo.x++;
	}
}

void    plotLine(t_vect vect, t_data *data)
{
	if (abs(vect.y1 - vect.y0) < abs(vect.x1 - vect.x0))
	{
		if (vect.x0 > vect.x1)
			plotLineLow(1, vect, data);
		else
			plotLineLow(0, vect, data);
	}
	else
	{
		if (vect.y0 > vect.y1)
			plotLineHigh(1, vect, data);
		else
			plotLineHigh(0, vect, data);
	}
}