/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:43:28 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 17:07:48 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int	i;
	int	n;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i])
	{
		n = 0;
		while (hay[i + n] == needle[n] && hay[i + n] != '\0')
		{
			if (needle[n + 1] == '\0')
				return ((char *)&hay[i]);
			n++;
		}
		i++;
	}
	return (0);
}
