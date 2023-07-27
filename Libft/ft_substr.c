/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:49:42 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 17:39:14 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*****************************************************************************
Function name:	ft_substr
Description:
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
Parameters:
	s:		The string from which to create the substring. start: The start 
			index of the substring in the string ’s’.
	start:	The index at which the string starts.
	len:	The maximum length of the substring.
Return value:
	The substring. NULL if the allocation fails.
******************************************************************************/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = ft_strlen (s);
	if (i <= start)
		return (ft_calloc(1, sizeof (char)));
	if (len > i - start)
		len = i - start;
	s2 = (char *) malloc ((len + 1) * sizeof (char));
	if (s2 == NULL)
		return (NULL);
	s2[0] = 0;
	s1 = (char *) &s[start];
	ft_strlcpy (s2, s1, len + 1);
	return (s2);
}
