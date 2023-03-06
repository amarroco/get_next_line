/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexie <alexie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2023/03/03 17:59:11 by alexie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoin_free(char *mem, char *buf)
{
	char	*temp;

	temp = ft_strjoin(mem, buf);
	free(mem);
	return (temp);
}

char	*ft_next(char *mem)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	if (ft_strchr(mem, '\n') == -1)
	{
		free(mem);
		return (NULL);
	}
	else
		i = ft_strchr(mem, '\n');
	dst = ft_calloc((ft_strlen(mem) - i + 1));
	i++;
	j = 0;
	while (mem[i])
		dst[j++] = mem[i++];
	free(mem);
	return (dst);
}

char	*ft_line(char *mem)
{
	char	*dst;
	int		i;

	i = 0;
	if (!*mem)
		return (NULL);
	if (ft_strchr(mem, '\n') != -1)
		i = ft_strchr(mem, '\n');
	else
		i = ft_strlen(mem);
	dst = ft_calloc(i + 2);
	i = 0;
	while (mem[i] && mem[i] != '\n')
	{
		dst[i] = mem[i];
		i++;
	}
	if (mem[i] && mem[i] == '\n')
		dst[i++] = '\n';
	return (dst);
}

char	*ft_read(int fd, char *mem)
{
	char	*buf;
	int		i;

	if (!mem)
		mem = ft_calloc(1);
	buf = ft_calloc(BUFFER_SIZE + 1);
	i = BUFFER_SIZE;
	while (i > 0 && ft_strchr(buf, '\n') == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		mem = ft_strjoin_free(mem, buf);
	}
	free(buf);
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	**mem;
	char		*d;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem[fd] = ft_read(fd, mem[fd]);
	if (!mem[fd])
		return (NULL);
	d = ft_line(mem[fd]);
	mem = ft_next(mem[fd]);
	return (d);
}
