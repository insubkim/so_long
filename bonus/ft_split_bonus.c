/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:15:26 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 01:59:58 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	cnt_word(char const *s, char c)
{
	int	i;
	int	flag;

	if (!s)
		return (0);
	i = 0 ;
	flag = 1;
	s--;
	while (*++s)
	{
		if (*s == c)
			flag = 1;
		else if (flag == 1)
		{
			i++;
			flag = 0;
		}
	}
	return (i);
}

static int	alloc(char **arr, char const *s, int i, int j)
{
	int	len;
	int	k;

	len = j - i + 1;
	*arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!*arr)
		return (0);
	(*arr)[len] = 0;
	k = 0;
	while (i <= j)
		(*arr)[k++] = s[i++];
	return (1);
}

static	int	put(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	flag;

	j = -1;
	flag = 1;
	while (s[++j])
	{
		if (s[j] == c)
		{
			if (flag == 0)
				if (!alloc(arr++, s, i, j - 1))
					return (0);
			flag = 1;
		}
		else if (flag == 1)
		{
			i = j;
			flag = 0;
		}
	}
	if (flag == 0)
		if (!alloc(arr, s, i, j - 1))
			return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**arr;

	word = cnt_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (0);
	arr[word] = 0;
	if (s && !put(arr, s, c))
	{
		while (*arr)
			free(*arr++);
		free(arr);
		return (0);
	}
	return (arr);
}
