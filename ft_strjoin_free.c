/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/23 23:54:19 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len;
	char	*p;
	int		i;

	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (*s2)
		p[i++] = *s2++;
	p[i] = 0;
	if (s1)
		free(s1);
	return (p);
}
