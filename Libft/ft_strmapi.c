/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:12:06 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 15:59:24 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*****************************************************************************
Function name:	ft_strmapi
Description:
	Applies the function ’f’ to each character of the string ’s’, and passing
	its index as first argument to create a new string (with malloc(3))
	resulting from successive applications of ’f’.
Parameters:
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value:
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
******************************************************************************/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = 0;
	while (s[len])
		len++;
	str = (char *) malloc ((len + 1) * sizeof (char));
	if (str == NULL)
		return (str);
	i = 0;
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[len] = 0;
	return (str);
}
