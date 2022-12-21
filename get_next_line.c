/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/21 06:07:20 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char **m)
{
	char		*b;
	int			i;
	
	b = ft_calloc(BUFFER_SIZE + 1);
	if (!b)
		return ;
	i = 1;
	while (((*m && ft_strchr(*m, '\n') == -1) || !*m) && i > 0)
	{
		i = read(fd, b, BUFFER_SIZE);
		printf("b : %s\n", b);
		if (i < 0)
			return (free(b), free(m));
		b[i] = 0;
		*m = ft_strjoin_free(*m, b);
		if (!m)
			return (free(b));
	}
	printf("read : %s\n", *m);
	free(b);
}

char	*ft_substr_free(char *s, int start, int len)
{
	char	*d;

	d = ft_substr(s, start, len);
	if (!d)
		return (NULL);
	free(s);
	return (d);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*d;

	d = ft_strjoin(s1, s2);
	if (!d)
		return (NULL);
	if (s1)
		free(s1);
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*m;
	char		*d;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_read(fd, &m);
	if (!m)
		return (NULL);
	printf("read ok\n");
	if (ft_strchr(m, '\n') == -1)
	{
		printf("return derniere ligne\n");
		return (m);
	}
	d = ft_substr(m, 0, ft_strchr(m, '\n'));
	if (!d)
		return (NULL);
	printf("d ok\n");
	m = ft_substr_free(m, ft_strchr(m, '\n') + 1, ft_strlen(m));
	if (!m)
		return (NULL);
	printf("m ok\n");
	return (d);
}
