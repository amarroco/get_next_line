/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2023/01/13 20:55:25 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_free(char *m, int start, int len)
{
	char	*d;

	d = ft_substr(m, start, len);
	if (!d)
		return (NULL);
	free (m);
	return (d);
}

char	*ft_strjoin_free(char *m, char *b)
{
	char	*d;
	
	d = ft_strjoin(m, b);
	if (!d)
		return (NULL);
	free (m);
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*m;
	char		*d;
	char		*b;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	b = malloc(BUFFER_SIZE + 1);
	if (!b)
		return (NULL);
	i = BUFFER_SIZE;
	while (ft_strchr(*m, '\n') == -1 && i > 0)
	{
		ft_bzero(b);
		i = read(fd, b, BUFFER_SIZE);
		if (i < 0)
			return (free(b), free(m));
		m = ft_strjoin_free(m, b);
		if (!m)
			return (free(b));
	}
	if (ft_strchr(m, '\n') == -1)
		return (m);
	d = ft_substr(m, 0, ft_strchr(m, '\n'));
	if (!d)
		return (free(m));
	m = ft_substr_free(m, ft_strchr(m, '\n') + 1, ft_strlen(m));
	return (d);
}
