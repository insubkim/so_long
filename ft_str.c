/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/12 20:49:47 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strcmp(char *s1, char *s2)
{
        while (*s1 == *s2)
        {
                if (*s1++ == 0)
                        return (0);
                s2++;
        }
        return ((unsigned char)*s1 - (unsigned char)*s2);
}

int  ft_strlen(const char *s)
{
        int  i;

        i = 0;
        if (!s)
            return (0);
        while (*s++)
                i++;
        return (i);
}