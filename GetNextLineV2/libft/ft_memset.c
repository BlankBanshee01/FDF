/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:36:30 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/13 23:04:44 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int d, size_t n)
{
	int				i;
	unsigned char	*cast;

	i = 0;
	cast = (unsigned char *)ptr;
	while ((size_t)i < n)
		cast[i++] = (unsigned char)d;
	return (ptr);
}
