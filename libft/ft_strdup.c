/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:56:28 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/22 22:44:08 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*pro;

	i = 0;
	if (!(pro = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		pro[i] = str[i];
		i++;
	}
	pro[i] = '\0';
	return (pro);
}
