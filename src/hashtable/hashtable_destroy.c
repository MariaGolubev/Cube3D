/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_destroy.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 13:46:18 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/07 13:46:19 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	hashtable_destroy(t_hashtable *table, t_delfn fn)
{
	t_u64	hash;

	while (table->len-- > 0)
	{
		hash = table->index[table->len];
		hash_node_destroy(&table->array[hash], fn);
	}
	free(table->array);
	free(table->index);
	table->array = NULL;
	table->index = NULL;
	table->len = 0;
	table->bucket_count = 0;
	if (table->is_allocated)
		free(table);
}
