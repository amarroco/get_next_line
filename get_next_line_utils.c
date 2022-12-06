/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/06 03:44:57 by amarroco         ###   ########.fr       */
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

char	*ft_calloc(int nmemb)
{
	char	*d;

	if (nmemb < 1 || nmemb > 2147483647)
	{
		return (NULL);
	}
	d = (char *)malloc(nmemb);
	if (!d)
		return (NULL);
	while (nmemb--)
		d[nmemb] = 0;
	return (d);
}

char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	d = (char *)ft_calloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i++])
		d[i - 1] = s[i - 1];
	return (d);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*d;
	int		i;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	d = (char *)ft_calloc(len + 1);
	if (!d)
		return (NULL);
	while (i < len && start < ft_strlen(s))
		d[i++] = s[start++];
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
