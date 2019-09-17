/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:57:28 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/23 00:43:39 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *
					sizeof(char))))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		str[i++] = s1[n++];
	n = 0;
	while (s2[n])
	{
		str[i] = s2[n];
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}
