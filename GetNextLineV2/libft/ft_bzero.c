/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:09:21 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/16 22:12:34 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cast;

	i = 0;
	if (n == 0)
		return ;
	cast = (unsigned char *)s;
	while (i < n)
	{
		cast[i] = 0;
		i++;
	}
}
