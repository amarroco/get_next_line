/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:27:22 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/03 14:33:56 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (c == 0)
	{
		return (ptr);
	}
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	len;
	size_t	i;

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

char	*get_next_line(int fd)
{
	static char *mem;
	char *buffer;
	char *d;
	int i;

	if (!mem)
		mem = ft_calloc(BUFFER_SIZE);
	if (!mem)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
			{
				d = mem;
			}
		}
	}
	return (d);
}