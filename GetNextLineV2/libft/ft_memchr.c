/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:22:22 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/17 01:58:31 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char		*caststr;
	unsigned char			castc;
	unsigned int			i;

	caststr = (const unsigned char *)str;
	castc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (caststr[i] == castc)
			return ((void *)caststr + i);
		i++;
	}
	return (NULL);
}
