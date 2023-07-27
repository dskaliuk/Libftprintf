/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:38:09 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 19:43:14 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*****************************************************************************
Function name:	ft_putstr_fd
Description:
	Outputs the string ’s’ to the given file descriptor.
Parameters:
	s: The string to output.
	fd: The file descriptor on which to write.
Return value:
	None.
******************************************************************************/

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}
