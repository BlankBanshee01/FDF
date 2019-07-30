/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:17:00 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 20:48:08 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	z;
	char	*str;

	if (!s)
		return (NULL);
	z = ft_strlen(s) - 1;
	while (s[z] == ' ' || s[z] == '\n' || s[z] == '\t')
		z--;
	i = 0;
	n = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	if (!(str = (char*)malloc((z - i + 2) * sizeof(char))))
		return (NULL);
	while (i <= z)
		str[n++] = s[i++];
	str[n] = '\0';
	return (str);
}
