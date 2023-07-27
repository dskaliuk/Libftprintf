/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:45 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/06/29 17:04:58 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s);

/*****************************************************************************
Function name:	ft_strnchr
Description:	Finds the '\n' character in the string and returns a pointer 
	to the next character.
Parameters:		s: The string.
Return value:	The pointer to the character, following the '\n' character
	in the string. Returns 0 if the string does not exist or ther is no '\n'
	character in the string.
******************************************************************************/
char	*ft_strnchr(char *s)
{
	if (!s)
		return (0);
	while (*s && *s != '\n')
		s++;
	if (*s != '\n')
		return (0);
	return (s + 1);
}

/*****************************************************************************
Function name:	ft_addbuf
Description:	Adds to the string 'str' the number of characters 'size' from
	the string 'buf'.
Parameters:		str:	The original string.
				buf: 	The string, from which characters are copied.
				size:	Number of copied characters.
Return value:	The pointer to the new resulting string. The original string
	deleted.
******************************************************************************/
char	*ft_addbuf(char *str, char *buf, ssize_t size)
{
	char	*s;
	ssize_t	i;
	ssize_t	j;

	/*j = 0;
	if (str)
	{
		while (str[j])
			j++;
	}*/
	j = ft_strlen (str);
	s = malloc (j + size + 1);
	if (!s)
	{
		free (str);
		return (0);
	}
	i = -1;
	while (++i < j)
		s[i] = str[i];
	j = 0;
	while (j < size)
		s[i++] = buf[j++];
	s[i] = 0;
	free (str);
	return (s);
}

char	*ft_readstr(int fd, char *s)
{
	ssize_t	n;
	int		flag;
	char	*buf;

	buf = (char *) malloc (BUFFER_SIZE * sizeof (char));
	n = 0;
	if (buf)
	{
		flag = !s;
		while (flag || !ft_strnchr(s))
		{
			flag = 0;
			n = read (fd, buf, BUFFER_SIZE);
			if (n <= 0)
				break ;
			s = ft_addbuf (s, buf, n);
		}
		free (buf);
	}
	if ((s && *s == 0 && n == 0) || n < 0)
	{
		free (s);
		s = 0;
	}
	return (s);
}
//printf ("ft_readstr:   n = %lli\n", n);
//printf ("ft_readstr: buf = %s\n", buf);
//printf ("ft_readstr:   s = %s\n", s);

char	*ft_getline(char *s)
{
	char	*line;
	ssize_t	len;
	ssize_t	i;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	line = malloc (len + 1);
	if (!line)
	{
		*s = 0;
		return (0);
	}
	line[len] = 0;
	i = -1;
	while (++i < len)
		line[i] = s[i];
	return (line);
}

char	*ft_delline(char *s)
{
	char	*linebuf;
	char	*startp;
	ssize_t	len;
	ssize_t	i;

	if (!s)
		return (0);
	linebuf = 0;
	startp = ft_strnchr (s);
	if (startp && *startp)
	{
		len = 0;
		while (startp[len])
			len++;
		linebuf = malloc (len + 1);
		if (!linebuf)
			return (0);
		i = -1;
		while (++i < len + 1)
			linebuf[i] = startp[i];
	}
	free (s);
	return (linebuf);
}

//printf("ft_delline: \\n = %hhi, ft_strnchr = %hhi\n", '\n', *startp);
//printf("ft_delline:          s = %s\n", s);
//printf("ft_delline: ft_strnchr = %s\n", startp);