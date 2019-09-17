/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:35:55 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/17 14:36:03 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*casts1;
	const unsigned char		*casts2;
	size_t					i;

	casts1 = (const unsigned char *)s1;
	casts2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (casts1[i] == casts2[i])
			i++;
		else
			return (casts1[i] - casts2[i]);
	}
	return (0);
}
