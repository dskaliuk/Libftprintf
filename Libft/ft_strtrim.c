/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:22 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 17:46:22 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/******************************************************************************
Function name:	ft_strtrim
Description:
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
Parameters:
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
Return value:
	The trimmed string. NULL if the allocation fails.
******************************************************************************/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*st;
	char	*s;

	if (*set == 0)
		return (ft_strdup (s1));
	i = 0;
	while (s1[i] && ft_strchr (set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup (""));
	st = (char *) &s1[i];
	i = ft_strlen (st);
	while (i >= 1 && ft_strchr (set, st[i - 1]))
		i--;
	s = (char *) malloc ((i + 1) * sizeof (char));
	if (s == NULL)
		return (NULL);
	ft_strlcpy (s, st, i + 1);
	return (s);
}
