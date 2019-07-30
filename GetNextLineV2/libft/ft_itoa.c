/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:09:15 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/22 14:50:40 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	i;
	int	x;

	x = n;
	if (n < 0)
		x = n * -1;
	i = 0;
	while (x >= 10)
	{
		i++;
		x = x / 10;
	}
	if (n < 0)
		return (i + 2);
	else
		return (i + 1);
}

char		*ft_itoa(int n)
{
	unsigned int	i;
	char			*str;
	int				b;
	int				x;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = size(n);
	i = 0;
	x = n;
	if (!(str = (char *)malloc((b + 1) * sizeof(char))))
		return (NULL);
	str[b] = '\0';
	b = b - 1;
	if (n < 0)
		x = n * -1;
	while (b >= 0)
	{
		str[b--] = ((x % 10) + 48);
		x = x / 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
