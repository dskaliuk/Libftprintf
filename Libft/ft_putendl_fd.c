/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:47:50 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 19:51:27 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*****************************************************************************
Function name:	ft_putendl_fd
Description:
	Outputs the string ’s’ to the given file descriptor followed by a newline.
Parameters:
	s: The string to output.
	fd: The file descriptor on which to write.
Return value:
	None.
******************************************************************************/

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}
