/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/13 20:17:56 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(char *s, int n)
{
	while (n--)
	{
		s[n] = 0;
	}
}

char	*ft_calloc(int nmemb)
{
	char	*d;

	if (nmemb < 1)
	{
		return (malloc(0));
	}
	d = (char *)malloc(nmemb);
	if (!d)
		return (NULL);
	ft_bzero(d,	nmemb);
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s2 && s1)
		return ((char *)s1);
	len = 0;
	i = 0;
	d = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (NULL);
	while (s1[len])
	{
		d[len] = s1[len];
		len++;
	}
	while (s2[i])
		d[len++] = s2[i++];
	return (d);
}
