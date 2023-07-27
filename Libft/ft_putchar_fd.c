/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:31:30 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 19:40:58 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*****************************************************************************
Function name:	ft_putchar_fd
Description:
	Outputs the character ’c’ to the given file descriptor.
Parameters:
	c: The character to output.
	fd: The file descriptor on which to write.
Return value:
	None.
******************************************************************************/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
