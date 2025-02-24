/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtok.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 14:09:31 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/28 14:14:07 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*current = NULL;
	char		*start;

	if (str != NULL)
		current = str;
	if (current == NULL)
		return (NULL);
	while (*current && ft_strchr(delim, *current) != NULL)
		current++;
	if (*current == '\0')
	{
		current = NULL;
		return (NULL);
	}
	start = current;
	while (*current && ft_strchr(delim, *current) == NULL)
		current++;
	if (*current)
	{
		*current = '\0';
		current++;
	}
	return (start);
}
