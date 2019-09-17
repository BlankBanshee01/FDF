/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:34:41 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 17:07:01 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t z)
{
	size_t i;
	size_t n;
	size_t need_len;

	i = 0;
	n = 0;
	need_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i] && i < z)
	{
		n = 0;
		while (hay[i + n] == needle[n] && hay[i + n] && i + n < z)
		{
			if (n == need_len - 1)
				return ((char *)&hay[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}
