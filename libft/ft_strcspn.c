/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcspn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/01 13:58:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/01 13:58:34 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(reject, str[i]) == NULL)
		i++;
	return (i);
}
