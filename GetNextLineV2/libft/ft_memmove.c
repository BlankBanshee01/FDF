/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:42:05 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/17 01:19:38 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*castsrc;
	char		*castdest;
	size_t		i;

	castsrc = (const char*)src;
	castdest = (char*)dest;
	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			castdest[i] = castsrc[i];
			i++;
		}
		return (dest);
	}
	else
	{
		while (n)
		{
			castdest[n - 1] = castsrc[n - 1];
			n--;
		}
		return (dest);
	}
}
