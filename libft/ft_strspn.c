/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strspn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 13:56:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/01 13:57:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str, const char *access)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(access, str[i]) != NULL)
		i++;
	return (i);
}
