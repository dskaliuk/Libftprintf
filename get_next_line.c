/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:08 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/06/29 16:24:46 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readstr(int fd, char *s);
char	*ft_getline(char *s);
char	*ft_delline(char *s);



char	*get_next_line(int fd)
{
	static char	*linebuf = 0;
	char		*line;

	if (fd < 0)
		return (NULL);
	linebuf = ft_readstr (fd, linebuf);
	line = ft_getline(linebuf);
	linebuf = ft_delline (linebuf);
	return (line);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}
//printf ("ft_readstr: linebuf = %s\n", linebuf);
//printf ("ft_getline:    line = %s\n", line);
//printf ("ft_delline: linebuf = %s\n", linebuf);