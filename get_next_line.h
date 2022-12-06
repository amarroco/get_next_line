/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 03:38:58 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/06 03:40:50 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_strlen(char *s);
char	*ft_calloc(int nmemb);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_next_line(char *mem, char *buf, int i);
char	*ft_get_memory(char *mem, char *buf, int i);
char	*get_next_line(int fd);

#endif