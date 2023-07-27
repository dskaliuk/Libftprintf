/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:26 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/25 18:21:59 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/******************************************************************************
Function name:	ft_strjoin
Description:
	Allocates (with malloc(3)) and returns a new string, which is the result
	of the concatenation of ’s1’ and ’s2’.
Parameters:
	s1: The prefix string.
	s2: The suffix string.
Return value:
	The new string. NULL if the allocation fails.
******************************************************************************/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	len = ft_strlen (s1) + ft_strlen (s2) + 1;
	s = (char *) malloc (len * sizeof (char));
	if (!s)
		return (s);
	ft_strlcpy (s, s1, len);
	ft_strlcat (s, s2, len);
	return (s);
}
