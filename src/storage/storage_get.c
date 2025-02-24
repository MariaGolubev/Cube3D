/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storage_get.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:26:30 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "storage.h"

void	*storage_get(t_storage *storage, const char *key)
{
	t_source	*source;

	source = hashtable_search(&storage->sources, ft_hashstr(key));
	if (source)
		return (source->ptr);
	return (NULL);
}
