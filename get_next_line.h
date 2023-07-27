/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:40:54 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/06/29 16:22:58 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE_DEFAULT 42

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER_SIZE_DEFAULT
# endif

char	*get_next_line(int fd);

#endif