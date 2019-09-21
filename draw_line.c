#include "fdf.h"

void    plotLineLow(int x0,int y0,int x1,int y1, t_data *data)
{
	int dx;
	int dy;
	int yi;
	int D;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = 2*dy - dx;
	y = y0;

	x = x0;
	while (x < x1)
	{
		ft_color_pixel(x,y, data);
		if (D > 0)
		{
			y = y + yi;
			D = D - 2*dx;
		}
		D = D + 2*dy;
        x++;
	}
}

void    plotLineHigh(int x0,int y0,int x1,int y1, t_data *data)
{
	int dx;
	int dy;
	int D;
	int x;
	int xi;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2*dx - dy;
	x = x0;
	y = y0;
        printf("\nherriii\n");

	while (y < y1)
	{
		ft_color_pixel(x,y, data);
		if (D > 0)
		{
			x = x + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
        y++;
	}
}

void    plotLine(int x0,int y0,int x1,int y1, t_data *data)
{  if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(x1, y1, x0, y0, data);
		else
			plotLineLow(x0, y0, x1, y1, data);
	}
	else
	{
		if (y0 > y1)
			plotLineHigh(x1, y1, x0, y0, data);
		else
			plotLineHigh(x0, y0, x1, y1, data);
	}
}