/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_to_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 11:58:27 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/19 13:26:38 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_read_to_str(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*str;
	char	*tmp;
	size_t	len;

	str = NULL;
	tmp = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(str), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		len = ft_strlen(str);
		tmp = (char *)ft_realloc((void *)str, len, len + bytes_read + 1);
		if (tmp == NULL)
			return (free(str), NULL);
		ft_memcpy(&tmp[len], buffer, bytes_read + 1);
		str = tmp;
	}
	return (str);
}
