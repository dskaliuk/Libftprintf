/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:05:54 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 14:58:00 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_num_of_strings(char *str, char c)
{
	size_t	n;
	int		flag;

	n = 0;
	while (*str)
	{
		flag = 0;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			str++;
			flag = 1;
		}
		if (flag)
			n++;
	}
	return (n);
}

static size_t	ft_string_len(char *str, char c)
{
	size_t			len;

	while (*str && *str == c)
		str++;
	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_write_str(char *dest, char *str, char c)
{
	while (*str && *str == c)
	{
		str++;
	}
	while (*str && *str != c)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = 0;
	return (str);
}

static void	ft_memfree(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

/******************************************************************************
Function name:	ft_split
Description:
	Allocates (with malloc(3)) and returns an array of strings obtained by
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
Parameters:
	s: The string to be split.
	c: The delimiter character.
Return value:
	The array of new strings resulting from the split.
	NULL if the allocation fails.
******************************************************************************/

char	**ft_split(char const *s, char c)
{
	size_t	n;
	size_t	len;
	size_t	i;
	char	**a;

	n = ft_num_of_strings((char *) s, c);
	a = (char **) malloc ((n + 1) * sizeof (char *));
	if (a == NULL)
		return (NULL);
	a[n] = NULL;
	i = 0;
	while (i < n)
	{
		len = ft_string_len ((char *) s, c);
		a[i] = (char *) malloc ((len + 1) * sizeof (char));
		if (a[i] == NULL)
		{
			ft_memfree (a);
			return (NULL);
		}
		s = ft_write_str (a[i], (char *) s, c);
		i++;
	}
	return (a);
}
