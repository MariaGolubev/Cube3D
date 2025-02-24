/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtok_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 22:59:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 16:48:23 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*start;

	if (str != NULL)
		*saveptr = str;
	if (*saveptr == NULL)
		return (NULL);
	while (**saveptr && ft_strchr(delim, **saveptr) != NULL)
		(*saveptr)++;
	if (**saveptr == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	start = *saveptr;
	while (**saveptr && ft_strchr(delim, **saveptr) == NULL)
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = '\0';
		(*saveptr)++;
	}
	return (start);
}
