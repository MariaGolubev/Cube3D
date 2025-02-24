/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 23:32:28 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/01/20 23:32:29 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_hashstr(const char *str)
{
	unsigned long	hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash);
}
