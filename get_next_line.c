/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/11 05:01:30 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_free(char *s, int start, int len);
{
	char	*d;

	d = ft_substr(s, start, len);
	if (!d)
		return (NULL);
	if (s)
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
	char		*b;
	char		*d;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	b[BUFFER_SIZE] = 0;
	while (ft_strchr(m, '\n') == -1 && read(fd, b, BUFFER_SIZE) >= 0)
	{
		m = ft_strjoin_free(m, b);
		if (!m)
			return (NULL);
	}
	if (ft_strchr(m, '\n') >= 0)
	{
		d = ft_substr(m, 0, ft_strchr(m, '\n'));
		if (!d)
			return (NULL);
		m = ft_substr_free(m, ft_strchr(m, '\n') + 1, ft_strlen(m));
		if (!m)
			return (NULL);
		return (d);
	}
	return ((char *)m );
}
