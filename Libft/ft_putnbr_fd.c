/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:54:36 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 21:02:59 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_num(int fd, unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_write_num (fd, n / 10);
		ft_write_num (fd, n % 10);
	}
	else
	{
		c = (char) n + '0';
		write (fd, &c, 1);
	}
}
/*****************************************************************************
Function name:	ft_putnbr_fd
Description:
	Outputs the integer ’n’ to the given file descriptor.
Parameters:
	n: The integer to output.
	fd: The file descriptor on which to write.
Return value:
	None.
******************************************************************************/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nu;

	if (n < 0)
	{
		nu = (unsigned int) -n;
		write (fd, "-", 1);
	}
	else
		nu = (unsigned int) n;
	ft_write_num (fd, nu);
}
