/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/06 03:45:07 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*d;

	d = ft_strjoin(s1, s2);
	if (!d)
		return (NULL);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (d);
}

char	*ft_next_line(char *mem, char *buf, int i)
{
	char	*d;

	if (i < 0)
	{
		if (!mem)
			return (NULL);
		d = ft_strdup(mem);
		free(mem);
	}
	if (i >= 0)
	{
		d = ft_strjoin_free(mem, ft_substr(buf, 0, ft_strchr(buf, '\n') + 1));
		if (!d)
			return (NULL);
	}
	return (d);
}

char	*ft_get_memory(char *mem, char *buf, int i)
{
	char	*d;

	if (ft_strlen(buf) - 1 == ft_strchr(buf, '\n'))
		return (NULL);
	if (i > 0)
	{
		d = ft_substr(buf, i, ft_strlen(buf) - i);
		if (!d)
			return (NULL);
	}
	else
	{
		d = ft_strjoin(mem, buf);
		if (!d)
			return (NULL);
		free(mem);
	}
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*buf;
	char		*d;
	int			i;

	i = read(fd, buf, BUFFER_SIZE);
	if (ft_strchr(buf, '\n') != -1)
	{
		d = ft_next_line(mem, buf, i);
		if (!d)
			return (NULL);
	}
	mem = ft_get_memory(mem, buf, ft_strchr(buf, '\n') + 1);
	if (ft_strchr(buf, '\n') == -1)
	{
		d = get_next_line(fd);
		if (!d)
			return (NULL);
	}
	return (d);
}
