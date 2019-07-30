/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:11:04 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 18:40:29 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*strone;
	unsigned char	*strtwo;

	strone = (unsigned char *)str1;
	strtwo = (unsigned char *)str2;
	i = 0;
	while (strone[i] && strtwo[i] && strone[i] == strtwo[i])
		i++;
	return (strone[i] - strtwo[i]);
}
