/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:16:16 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 18:41:29 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*strone;
	unsigned char	*strtwo;

	strone = (unsigned char *)str1;
	strtwo = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (strone[i] && strtwo[i] && strone[i] == strtwo[i] && i < n - 1)
		i++;
	return (strone[i] - strtwo[i]);
}
