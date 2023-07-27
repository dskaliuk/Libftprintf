/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:19 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/28 15:28:13 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*****************************************************************************
Function name:	memset / ft_memset
Description:
	Fill a byte string with a byte value.
	The memset() function writes len bytes of value c (converted to an
	unsigned char) to the string b.
Parameters:
	b:	 The string.
	c:	 The value to write.
	len: The number of bytes to write.
Return value:
	The memset() function returns its first argument, b.
******************************************************************************/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	uc;

	p = (unsigned char *) b;
	uc = (unsigned char) c;
	while (len)
	{
		*p = uc;
		p++;
		len--;
	}
	return (b);
}
