/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable_insert.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 21:00:14 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/06 12:38:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void	insert(t_hash_node *node, t_u64 key, void *value)
{
	node->key = key;
	node->value = value;
}

static void	update(t_hash_node *node, t_u64 key, void *value, t_delfn fn)
{
	if (fn != NULL)
		fn(node->value);
	node->key = key;
	node->value = value;
}

int	hashtable_insert(t_hashtable *table, t_u64 key, void *value, t_delfn fn)
{
	t_u64	hash;
	t_u64	i;

	if (table->len == table->bucket_count || value == NULL)
		return (1);
	i = 0;
	while (i < table->bucket_count)
	{
		hash = (key + i * i) % table->bucket_count;
		if (table->array[hash].key == key)
		{
			update(&table->array[hash], key, value, fn);
			break ;
		}
		else if (table->array[hash].value == NULL)
		{
			insert(&table->array[hash], key, value);
			table->index[table->len] = hash;
			table->len++;
			break ;
		}
		i++;
	}
	return (0);
}
