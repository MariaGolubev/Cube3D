/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   storage_add.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 20:22:39 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "storage.h"

int	storage_add(t_storage *storage, const char *key, void *source, t_del_fn del)
{
	t_source	*new_source;

	new_source = (t_source *)malloc(sizeof(t_source));
	if (new_source == NULL)
	{
		if (del)
			del(source);
		return (1);
	}
	new_source->ptr = source;
	new_source->del = del;
	if (hashtable_insert(&storage->sources, ft_hashstr(key), new_source,
			source_destroy) != 0)
	{
		if (del)
			del(source);
		free(new_source);
		return (2);
	}
	return (0);
}
