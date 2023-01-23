/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/23 23:54:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1++ == 0)
			return (0);
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
		if (s[i--] == (char)c)
			return ((char *)&(s[++i]));
	return (0);
}

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = (char)c;
	return (b);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		tmp;

	tmp = n;
	len = 1;
	while (tmp >= 10)
	{
		len++;
		tmp = tmp / 10;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		handle_error(MALLOC_ERROR);
	arr[len] = 0;
	while (len-- > 0)
	{
		arr[len] = n % 10 + '0';
		n = n / 10;
	}
	return (arr);
}
