/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:20:14 by amarroco          #+#    #+#             */
/*   Updated: 2022/12/21 04:35:46 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
  char	*test;
  int	fd;
  
  fd = open("text.txt", O_RDONLY);
  printf("fd : %i\n", fd);
  test = get_next_line(fd);
  while (test)
  {  
      printf("ligne : %s", test);
      free(test);
      test = get_next_line(fd);
  }
  close(fd);
}
